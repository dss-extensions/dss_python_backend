// This C extension contains a few faster alternatives for some functions
#include <Python.h>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/ndarrayobject.h"
#include <stdint.h>
#include <string.h>

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
typedef void (*gr_func_ctx_t)(const void* ctx);
typedef void (*gr_func_ctx_int32_t)(const void* ctx, int32_t value);

enum Signatures {
    Signature_empty = 0,
    Signature_int32 = 1,
    Signature_str = 2,
    Signature_float64 = 3,
    Signature_complex128 = 4,
    Signature_int8 = 5,
    Signature_float32 = 6,
    Signature_complex64 = 7,
    Signature_one_complex128 = 8

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
    void* func;
    func_str_ctx_t errorDescFunc;
    func_dispose_strlist_t disposeFunc;
    PyObject *DSSExceptionType;
    unsigned char funcArgSignature;
} AltDSSStrListFuncObject;

typedef struct
{
    PyObject_HEAD

    void *dssCtx;
    int32_t *errorPtr;
    void* func;
    func_str_ctx_t errorDescFunc;

    // GR pointers
    void *dataPtr;
    int32_t *countPtr;

    int32_t *settingsPtr;

    PyObject *DSSExceptionType;
    unsigned char funcArgSignature;
    unsigned char resType;
} AltDSSGRArrayFuncObject;


static PyObject *AltDSSGRArrayFunc_set_exc_type(AltDSSGRArrayFuncObject *f, PyObject *arg)
{
    Py_DECREF(f->DSSExceptionType);
    f->DSSExceptionType = arg;
    Py_INCREF(arg);
    Py_RETURN_NONE;
}

static int AltDSSGRArrayFunc_init(AltDSSGRArrayFuncObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    unsigned long long dssCtx, errorPtr, func, errorDescFunc, dataPtr, countPtr, settingsPtr;
    if (!PyArg_ParseTuple(args, "KKKKKKKObb", &dssCtx, &errorPtr, &func, &errorDescFunc, 
        &dataPtr, &countPtr, &settingsPtr, &f->DSSExceptionType, &f->funcArgSignature, &f->resType))
    {
        PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSSGRArrayFunc initialization");
        return -1;
    }
    f->dssCtx = (void*) dssCtx;
    f->errorPtr = (int32_t*) errorPtr;
    f->func = (void*) func;
    f->errorDescFunc = (func_str_ctx_t) errorDescFunc;
    f->dataPtr = (void*) dataPtr;
    f->countPtr = (int32_t*) countPtr;
    f->settingsPtr = (int32_t*) settingsPtr;
    Py_INCREF(f->DSSExceptionType);
    return 0;
}

static PyObject *AltDSSGRArrayFunc_call(AltDSSGRArrayFuncObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    PyObject *result = NULL;
    int argValue;
    int32_t resType = f->resType;
    int32_t settings = *f->settingsPtr;
    int nd = 1;
    npy_intp dims[2];
    void *data;

    switch (f->funcArgSignature)
    {
        case Signature_int32:
            if (!PyArg_ParseTuple(args, "i", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSSStrFunc call (expected an integer value)");
                return NULL;
            }
            ((gr_func_ctx_int32_t)f->func)(f->dssCtx, argValue);
            break;
        default:
            ((gr_func_ctx_t)f->func)(f->dssCtx);
            break;
    }
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

    //TODO: handle list option

    if (resType == Signature_complex128) //TODO: handle advanced types
    {
        resType = Signature_float64;
    }

    if (1)//(dims[2] == 0)) //TODO: handle advanced types
    {
        dims[0] = f->countPtr[0];
    }
    else
    {
        nd = 2;
        dims[0] = f->countPtr[2];
        dims[1] = f->countPtr[3];
    }

    switch (resType)
    {
        case Signature_one_complex128:
            if (f->countPtr[0] != 2)
            {
                PyErr_SetString(f->DSSExceptionType, "Unexpected number of elements returned by API (complex number).");
                return NULL;
            }
            return PyComplex_FromDoubles((*(double**)f->dataPtr)[0], (*(double**)f->dataPtr)[1]);
        case Signature_complex128:
            if (f->countPtr[0] & 1)
            {
                PyErr_SetString(f->DSSExceptionType, "Unexpected number of elements returned by API (array of complex numbers).");
                return NULL;
            }
            result = PyArray_SimpleNew(nd, dims, NPY_COMPLEX128);
            data = PyArray_DATA((PyArrayObject*) result);
            if (data == NULL)
                goto array_error;
            memcpy(data, *(double**)f->dataPtr, sizeof(double) * f->countPtr[0]);
            return result;
        case Signature_float64:
            result = PyArray_SimpleNew(nd, dims, NPY_FLOAT64);
            data = PyArray_DATA((PyArrayObject*) result);
            if (data == NULL)
                goto array_error;
            memcpy(data, *(double**)f->dataPtr, sizeof(double) * f->countPtr[0]);
            return result;
        // case Signature_float32:
        //     result = PyArray_SimpleNew(nd, dims, NPY_FLOAT32);
        //     memcpy(data, f->dataPtr[0], *(float**)f->dataPtr, sizeof(float) * f->countPtr[0]);
        //     data = PyArray_DATA(result);
        //     return result;
        case Signature_int32:
            result = PyArray_SimpleNew(nd, dims, NPY_INT32);
            data = PyArray_DATA((PyArrayObject*) result);
            if (data == NULL)
                goto array_error;
            memcpy(data, *(int32_t**)f->dataPtr, sizeof(int32_t) * f->countPtr[0]);
            return result;
        case Signature_int8:
            result = PyArray_SimpleNew(nd, dims, NPY_INT8);
            data = PyArray_DATA((PyArrayObject*) result);
            if (data == NULL)
                goto array_error;
            memcpy(data, *(int8_t**)f->dataPtr, sizeof(int8_t) * f->countPtr[0]);
            return result;
        default:
            PyErr_SetString(f->DSSExceptionType, "Invalid type specified.");
            return NULL;
    }
    return result;
array_error:
    Py_XDECREF(result);
    return NULL;
}

static PyMethodDef AltDSSGRArrayFunc_methods[] = {
    //{"__call__", (PyCFunction) AltDSSStrFunc_call, METH_NOARGS, "Call the low-level function, mapping the result string to Python, while checking for DSS errors."},
    {"set_exc_type", (PyCFunction) AltDSSGRArrayFunc_set_exc_type, METH_O, "Set the exception class to raise on DSS errors. If None, exceptions are disabled."},
    {NULL}
};

static PyTypeObject AltDSSGRArrayFuncType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_fast.AltDSSGRArrayFunc",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API function that returns a numeric array, handling DSS errors and runtime settings"),
    .tp_basicsize = sizeof(AltDSSGRArrayFuncObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSSGRArrayFunc_init,
    .tp_call = ((PyCFunctionWithKeywords) AltDSSGRArrayFunc_call),
    .tp_methods = AltDSSGRArrayFunc_methods,
};

static PyObject *AltDSSStrListFunc_set_exc_type(AltDSSStrListFuncObject *f, PyObject *arg)
{
    Py_DECREF(f->DSSExceptionType);
    f->DSSExceptionType = arg;
    Py_INCREF(arg);
    Py_RETURN_NONE;
}

static PyObject *AltDSSStrFunc_set_exc_type(AltDSSStrFuncObject *f, PyObject *arg)
{
    Py_DECREF(f->DSSExceptionType);
    f->DSSExceptionType = arg;
    Py_INCREF(arg);
    Py_RETURN_NONE;
}

static int AltDSSStrFunc_init(AltDSSStrFuncObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
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

static PyObject *AltDSSStrFunc_call(AltDSSStrFuncObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    PyObject *result = NULL;
    int argValue;
    char const* cstr;
    switch (f->funcArgSignature)
    {
        case Signature_int32:
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
    .tp_call = ((PyCFunctionWithKeywords) AltDSSStrFunc_call),
    .tp_methods = AltDSSStrFunc_methods,
};


static int AltDSSStrListFunc_init(PyObject *self, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    AltDSSStrListFuncObject *f = (AltDSSStrListFuncObject*) self;

    unsigned long long dssCtx, errorPtr, func, errorDescFunc, disposeFunc;
    if (!PyArg_ParseTuple(args, "KKKKKOb", &dssCtx, &errorPtr, &func, &errorDescFunc, &disposeFunc, &f->DSSExceptionType, &f->funcArgSignature))
    {
        PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSSStrListFunc initialization");
        return -1;
    }
    f->dssCtx = (void*) dssCtx;
    f->errorPtr = (int32_t*) errorPtr;
    f->func = (void*) func;
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
        case Signature_int32:
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
    .tp_call = ((PyCFunctionWithKeywords) AltDSSStrListFunc_call),
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

    if (sizeof(unsigned long long) < sizeof(void*))
    {
        PyErr_SetString(PyExc_TypeError, "Unexpected integer sizes!");
        return NULL;
    }

    import_array();

    if (
        PyType_Ready(&AltDSSStrFuncType) < 0 
        || PyType_Ready(&AltDSSStrListFuncType) < 0
        || PyType_Ready(&AltDSSGRArrayFuncType) < 0
    )
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
    Py_INCREF(&AltDSSGRArrayFuncType);
    if (PyModule_AddObject(m, "AltDSSGRArrayFunc", (PyObject *) &AltDSSGRArrayFuncType) < 0)
    {
        goto ERROR3;
    }

    return m;

ERROR3:
    Py_DECREF(&AltDSSGRArrayFuncType);
ERROR2:
    Py_DECREF(&AltDSSStrListFuncType);
ERROR1:
    Py_DECREF(&AltDSSStrFuncType);
    Py_DECREF(m);
    return NULL;
}
