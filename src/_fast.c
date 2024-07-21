#include <Python.h>
#include <stdint.h>

//TODO: 
// - direct integration with AltDSS
// - test if NULLs behave OK or the current checks are required
// PyLong_FromVoidPtr and PyLong_AsVoidPtr

typedef const char* (*func_str_ctx_t)(const void* ctx);
typedef const char* (*func_str_ctx_int32_t)(const void* ctx, int32_t value);
typedef void (*func_ctx_strlist_t)(const void* ctx, char*** ResultPtr, int32_t* ResultDims);
typedef void (*func_ctx_strlist_int32_t)(const void* ctx, char*** ResultPtr, int32_t* ResultDims, int32_t value);
typedef void (*func_ctx_strlist_pchar_t)(const void* ctx, char*** ResultPtr, int32_t* ResultDims, const char* value);
typedef void (*func_dispose_strlist_t)(char ***p, int32_t cnt);

enum Signatures {
    Signature_empty = 0,
    Signature_int = 1,
    Signature_str = 2
};

typedef struct
{
    PyObject_HEAD

    void *dssCtx;
    int32_t *errorPtr;
    void* func;
    func_str_ctx_t errorDescFunc;
    PyObject *DSSExceptionType;
    unsigned char funcArgSignature;
} AltDSSStrFuncObject;

typedef struct
{
    PyObject_HEAD

    void *dssCtx;
    int32_t *errorPtr;
    func_ctx_strlist_t func;
    func_str_ctx_t errorDescFunc;
    func_dispose_strlist_t disposeFunc;
    PyObject *DSSExceptionType;
    unsigned char funcArgSignature;
} AltDSSStrListFuncObject;

static PyObject *AltDSSStrListFunc_set_exc_type(PyObject *self, PyObject *arg)
{
    AltDSSStrListFuncObject *f = (AltDSSStrListFuncObject*) self;
    f->DSSExceptionType = arg;
    Py_INCREF(arg);
    return Py_None;
}

static PyObject *AltDSSStrFunc_set_exc_type(PyObject *self, PyObject *arg)
{
    AltDSSStrFuncObject *f = (AltDSSStrFuncObject*) self;
    f->DSSExceptionType = arg;
    Py_INCREF(arg);
    return Py_None;
}

static int AltDSSStrFunc_init(PyObject *self, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    AltDSSStrFuncObject *f = (AltDSSStrFuncObject*) self;

    if (sizeof(unsigned long long) < sizeof(void*))
    {
        PyErr_SetString(PyExc_TypeError, "Unexpected integer sizes!");
        return -1;
    }

    unsigned long long dssCtx, errorPtr, func, errorDescFunc;
    if (!PyArg_ParseTuple(args, "KKKKOb", &dssCtx, &errorPtr, &func, &errorDescFunc, &f->DSSExceptionType, &f->funcArgSignature))
    {
        PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSSStrFunc initialization");
        return -1;
    }
    f->dssCtx = (void*) dssCtx;
    f->errorPtr = (int32_t*) errorPtr;
    f->func = (void*) func;
    f->errorDescFunc = (func_str_ctx_t) errorDescFunc;
    Py_INCREF(f->DSSExceptionType);
    return 0;
}

static PyObject *AltDSSStrFunc_call(PyObject *self, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    AltDSSStrFuncObject *f = (AltDSSStrFuncObject*) self;
    PyObject *result = NULL;
    int argValue;
    char const* cstr;
    switch (f->funcArgSignature)
    {
        case Signature_int:
            if (!PyArg_ParseTuple(args, "i", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSSStrFunc call (expected an integer value)");
                return NULL;
            }
            cstr = ((func_str_ctx_int32_t)f->func)(f->dssCtx, argValue);
            break;
        default:
            cstr = ((func_str_ctx_t)f->func)(f->dssCtx);
            break;
    }
    //TODO: for Alt functions, we will need to dispose the C string later, 
    // or take ownership of the pointer.
    if (*f->errorPtr && f->DSSExceptionType != Py_None)
    {
        if (f->errorDescFunc != f->func)
        {
            const char *errorDesc = f->errorDescFunc(f->dssCtx);
            int32_t num = *f->errorPtr;
            *f->errorPtr = 0;
            //TODO: check ref count here
            PyErr_SetObject(f->DSSExceptionType, PyTuple_Pack(2, 
                PyLong_FromLong(num),
                PyUnicode_FromString(errorDesc)
            ));
            return NULL;
        }
        PyErr_SetString(f->DSSExceptionType, "Error mapping DSS error to Python!");
        return NULL;
    }
    result = cstr ? PyUnicode_FromString(cstr) : PyUnicode_FromString("");
    return result;
}

static PyMethodDef AltDSSStrFunc_methods[] = {
    //{"__call__", (PyCFunction) AltDSSStrFunc_call, METH_NOARGS, "Call the low-level function, mapping the result string to Python, while checking for DSS errors."},
    {"set_exc_type", (PyCFunction) AltDSSStrFunc_set_exc_type, METH_O, "Set the exception class to raise on DSS errors. If None, exceptions are disabled."},
    {NULL}
};

static PyTypeObject AltDSSStrFuncType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_fast.AltDSSStrFunc",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API plain str function, handling DSS errors"),
    .tp_basicsize = sizeof(AltDSSStrFuncObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSSStrFunc_init,
    .tp_call = AltDSSStrFunc_call,
    .tp_methods = AltDSSStrFunc_methods,
};


static int AltDSSStrListFunc_init(PyObject *self, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    AltDSSStrListFuncObject *f = (AltDSSStrListFuncObject*) self;

    if (sizeof(unsigned long long) < sizeof(void*))
    {
        PyErr_SetString(PyExc_TypeError, "Unexpected integer sizes!");
        return -1;
    }

    unsigned long long dssCtx, errorPtr, func, errorDescFunc, disposeFunc;
    if (!PyArg_ParseTuple(args, "KKKKKOb", &dssCtx, &errorPtr, &func, &errorDescFunc, &disposeFunc, &f->DSSExceptionType, &f->funcArgSignature))
    {
        PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSSStrListFunc initialization");
        return -1;
    }
    f->dssCtx = (void*) dssCtx;
    f->errorPtr = (int32_t*) errorPtr;
    f->func = (func_ctx_strlist_t) func;
    f->errorDescFunc = (func_str_ctx_t) errorDescFunc;
    f->disposeFunc = (func_dispose_strlist_t) disposeFunc;
    Py_INCREF(f->DSSExceptionType);
    return 0;
}


static PyObject *AltDSSStrListFunc_call(PyObject *self, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    AltDSSStrListFuncObject *f = (AltDSSStrListFuncObject*) self;
    PyObject *result = NULL;
    PyObject *item = NULL;
    char** cstr_list = NULL;
    char** sptr = NULL;
    int32_t count[4] = {0, 0, 0, 0};
    int32_t i;
    int argIntValue;
    char *argStrValue;

    switch (f->funcArgSignature)
    {
        case Signature_int:
            if (!PyArg_ParseTuple(args, "i", &argIntValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSSStrFunc call (expected an integer value)");
                return NULL;
            }
            ((func_ctx_strlist_int32_t)f->func)(f->dssCtx, &cstr_list, &count[0], argIntValue);
            break;
        case Signature_str:
            // TODO: use s# whenever possible
            if (!PyArg_ParseTuple(args, "s*", &argStrValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSSStrFunc call (expected either a string or bytes value)");
                return NULL;
            }
            ((func_ctx_strlist_pchar_t)f->func)(f->dssCtx, &cstr_list, &count[0], argStrValue);
            break;
        default:
            ((func_ctx_strlist_t)f->func)(f->dssCtx, &cstr_list, &count[0]);
            break;
    }

    if (*f->errorPtr && f->DSSExceptionType != Py_None)
    {
        const char *errorDesc = f->errorDescFunc(f->dssCtx);
        int32_t num = *f->errorPtr;
        *f->errorPtr = 0;
        //TODO: check ref count here
        PyErr_SetObject(f->DSSExceptionType, PyTuple_Pack(2, 
            PyLong_FromLong(num),
            PyUnicode_FromString(errorDesc)
        ));
        f->disposeFunc(&cstr_list, count[1]);
        return NULL;
    }

    result = PyList_New(count[0]);
    if (PyErr_Occurred())
    {
        f->disposeFunc(&cstr_list, count[1]);
        return NULL;
    }

    for (i = 0, sptr = cstr_list; i < count[0]; ++i, ++sptr)
    {
        item = (*sptr) ? PyUnicode_FromString(*sptr) : PyUnicode_FromString("");
        if (PyErr_Occurred())
        {
            Py_DECREF(result);
            f->disposeFunc(&cstr_list, count[1]);
            return NULL;
        }
        PyList_SetItem(result, i, item);
    }
    f->disposeFunc(&cstr_list, count[1]);
    return result;
}

static PyMethodDef AltDSSStrListFunc_methods[] = {
    //{"__call__", (PyCFunction) AltDSSStrListFunc_call, METH_NOARGS, "Call the low-level function, mapping the result string to Python, while checking for DSS errors."},
    {"set_exc_type", (PyCFunction) AltDSSStrListFunc_set_exc_type, METH_O, "Set the exception class to raise on DSS errors. If None, exceptions are disabled."},
    {NULL}
};

static PyTypeObject AltDSSStrListFuncType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_fast.AltDSSStrListFunc",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API function that returns an array of strings, handling DSS errors"),
    .tp_basicsize = sizeof(AltDSSStrListFuncObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSSStrListFunc_init,
    .tp_call = AltDSSStrListFunc_call,
    .tp_methods = AltDSSStrListFunc_methods,
};

static PyMethodDef funcs[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef altdss_fast_def = {
    PyModuleDef_HEAD_INIT, 
    "_fast", 
    "A couple of faster string handling functions; CPython only.\n",
    -1,
    funcs
};

PyMODINIT_FUNC PyInit__fast()
{
    PyObject *m;
    if (PyType_Ready(&AltDSSStrFuncType) < 0 || PyType_Ready(&AltDSSStrListFuncType) < 0)
    {
        return NULL;
    }

    m = PyModule_Create(&altdss_fast_def);
    if (m == NULL)
    {
        return NULL;
    }

    Py_INCREF(&AltDSSStrFuncType);
    if (PyModule_AddObject(m, "AltDSSStrFunc", (PyObject *) &AltDSSStrFuncType) < 0)
    {
        goto ERROR1;
    }
    Py_INCREF(&AltDSSStrListFuncType);
    if (PyModule_AddObject(m, "AltDSSStrListFunc", (PyObject *) &AltDSSStrListFuncType) < 0)
    {
        goto ERROR2;
    }

    return m;

ERROR2:
    Py_DECREF(&AltDSSStrListFuncType);
ERROR1:
    Py_DECREF(&AltDSSStrFuncType);
    Py_DECREF(m);
    return NULL;
}
