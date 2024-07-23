// This C extension contains a few faster alternatives for some functions
// TODO: PyLong_FromVoidPtr and PyLong_AsVoidPtr could be used?
// TODO: enums in int32 and one_int32 results, e.g. LoadModels
#ifndef ALTDSS_FAST_MODINIT
#error "Define ALTDSS_FAST_MODNAME"
#endif

#define PY_SSIZE_T_CLEAN
// #define Py_LIMITED_API 0x03070000
#include <Python.h>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/ndarrayobject.h"
#include "../dss_python_backend/include/dss_capi_ctx.h"

typedef int32_t (*func_int32_ctx_int32_t)(const void* ctx, int32_t value);
typedef int32_t (*func_int32_ctx_t)(const void* ctx);

typedef double (*func_float64_ctx_int32_t)(const void* ctx, int32_t value);
typedef double (*func_float64_ctx_t)(const void* ctx);

typedef uint16_t (*func_bool_ctx_int32_t)(const void* ctx, int32_t value);
typedef uint16_t (*func_bool_ctx_t)(const void* ctx);

typedef const char* (*func_str_ctx_t)(const void* ctx);
typedef const char* (*func_str_ctx_int32_t)(const void* ctx, int32_t value);
typedef void (*func_ctx_strlist_t)(const void* ctx, char*** ResultPtr, int32_t* ResultDims);
typedef void (*func_ctx_strlist_int32_t)(const void* ctx, char*** ResultPtr, int32_t* ResultDims, int32_t value);
typedef void (*func_ctx_strlist_pchar_t)(const void* ctx, char*** ResultPtr, int32_t* ResultDims, const char* value);
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
    Signature_one_complex128 = 8,
    Signature_one_int32 = 9,
    Signature_one_float64 = 10,
    Signature_str_list = 11,
    Signature_one_bool = 12,
};

struct AltDSS_PyContextObject_;

typedef struct
{
    PyObject_HEAD

    void *dssCtx;
    int32_t *errorPtr;
    void* func;
    int32_t *settingsPtr;
    struct AltDSS_PyContextObject_* parent;

    unsigned char funcArgSignature;
    unsigned char resType;
} AltDSS_PyStrGetterObject;

typedef struct
{
    PyObject_HEAD

    void *dssCtx;
    int32_t *errorPtr;
    void* func;
    int32_t *settingsPtr;
    struct AltDSS_PyContextObject_* parent;

    unsigned char funcArgSignature;
    unsigned char resType;
} AltDSS_PyStrListGetterObject;


typedef struct
{
    PyObject_HEAD

    void *dssCtx;
    int32_t *errorPtr;
    void* func;
    int32_t *settingsPtr;
    struct AltDSS_PyContextObject_* parent;

    unsigned char funcArgSignature;
    unsigned char resType;
} AltDSS_PyScalarGetterObject;


typedef struct
{
    PyObject_HEAD

    void *dssCtx;
    int32_t *errorPtr;
    void* func;
    int32_t *settingsPtr;
    struct AltDSS_PyContextObject_* parent;

    unsigned char funcArgSignature;
    unsigned char resType;

    // GR pointers
    void *dataPtr;
    int32_t *countPtr;
} AltDSS_PyGRGetterObject;

typedef struct AltDSS_PyContextObject_
{
    PyObject_HEAD

    void *dssCtx;
    int32_t *errorPtr;
    PyObject *DSSExceptionType;
    int32_t *settingsPtr;

    double **dataPtr_pdouble;
    int32_t** dataPtr_pinteger;
    int8_t** dataPtr_pbyte;

    int32_t* countPtr_pdouble;
    int32_t* countPtr_pinteger;
    int32_t* countPtr_pbyte;

    #include "./_fast_struct_members.inc.c"
} AltDSS_PyContextObject;

static int AltDSS_PyScalarGetter_init(AltDSS_PyScalarGetterObject *f, PyObject *Py_UNUSED(args_ignored), PyObject *Py_UNUSED(kwargs_ignored))
{
    f->parent = NULL;
    f->dssCtx = NULL;
    f->func = NULL;
    return 0;
}

static int AltDSS_PyGRGetter_init(AltDSS_PyGRGetterObject *f, PyObject *Py_UNUSED(args_ignored), PyObject *Py_UNUSED(kwargs_ignored))
{
    f->parent = NULL;
    f->dssCtx = NULL;
    f->func = NULL;
    return 0;
}

static int AltDSS_PyStrGetter_init(AltDSS_PyStrGetterObject *f, PyObject *PyUNUSED(args_ignored), PyObject *Py_UNUSED(kwargs_ignored))
{
    f->parent = NULL;
    f->func = NULL;
    f->dssCtx = NULL;
    return 0;
}

static int AltDSS_PyStrListGetter_init(AltDSS_PyStrListGetterObject *f, PyObject *Py_UNUSED(args_ignored), PyObject *Py_UNUSED(kwargs_ignored))
{
    f->dssCtx = NULL;
    f->parent = NULL;
    f->func = NULL;
    return 0;
}

static PyObject *AltDSS_PyScalarGetter_call(AltDSS_PyScalarGetterObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    PyObject *result = NULL;
    int argValue;
    int32_t cval_int32;
    double cval_float64;
    
    switch (f->funcArgSignature)
    {
        case Signature_one_int32:
            if (!PyArg_ParseTuple(args, "i", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarGetter call (expected an integer value)");
                return NULL;
            }
            break;
        case Signature_empty:
            break;
        default:
            PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (unknown signature)");
            return NULL;
    }

    switch (f->resType)
    {
        case Signature_one_bool:
        switch (f->funcArgSignature)
        {
            case Signature_one_int32:
                cval_int32 = ((func_bool_ctx_int32_t)f->func)(f->dssCtx, argValue);
                break;
            default:
                cval_int32 = ((func_bool_ctx_t)f->func)(f->dssCtx);
                break;
        }
        break;
        case Signature_one_int32:
        switch (f->funcArgSignature)
        {
            case Signature_one_int32:
                cval_int32 = ((func_int32_ctx_int32_t)f->func)(f->dssCtx, argValue);
                break;
            default:
                cval_int32 = ((func_int32_ctx_t)f->func)(f->dssCtx);
                break;
        }
        break;
        case Signature_one_float64:
        switch (f->funcArgSignature)
        {
            case Signature_one_int32:
                cval_float64 = ((func_float64_ctx_int32_t)f->func)(f->dssCtx, argValue);
                break;
            default:
                cval_float64 = ((func_float64_ctx_t)f->func)(f->dssCtx);
                break;
        }
        break;
    }

    if (*f->errorPtr && f->parent->DSSExceptionType != Py_None)
    {
        if (ctx_Error_Get_Description != f->func)
        {
            const char *errorDesc = ctx_Error_Get_Description(f->dssCtx);
            int32_t num = *f->errorPtr;
            *f->errorPtr = 0;
            //TODO: check ref count here
            PyErr_SetObject(f->parent->DSSExceptionType, PyTuple_Pack(2, 
                PyLong_FromLong(num),
                PyUnicode_FromString(errorDesc)
            ));
            return NULL;
        }
        PyErr_SetString(f->parent->DSSExceptionType, "Error mapping DSS error to Python!");
        return NULL;
    }

    switch (f->resType)
    {
        case Signature_one_bool:
            return (cval_int32 ? Py_True : Py_False);
        case Signature_one_int32:
            return PyLong_FromLong(cval_int32);
        case Signature_one_float64:
            return PyFloat_FromDouble(cval_float64);
    }
    return NULL;
}

static PyObject *AltDSS_PyGRGetter_call(AltDSS_PyGRGetterObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
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
        case Signature_one_int32:
            if (!PyArg_ParseTuple(args, "i", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (expected an integer value)");
                return NULL;
            }
            ((gr_func_ctx_int32_t)f->func)(f->dssCtx, argValue);
            break;
        default:
            ((gr_func_ctx_t)f->func)(f->dssCtx);
            break;
    }
    if (*f->errorPtr && f->parent->DSSExceptionType != Py_None)
    {
        if (ctx_Error_Get_Description != f->func)
        {
            const char *errorDesc = ctx_Error_Get_Description(f->dssCtx);
            int32_t num = *f->errorPtr;
            *f->errorPtr = 0;
            //TODO: check ref count here
            PyErr_SetObject(f->parent->DSSExceptionType, PyTuple_Pack(2, 
                PyLong_FromLong(num),
                PyUnicode_FromString(errorDesc)
            ));
            return NULL;
        }
        PyErr_SetString(f->parent->DSSExceptionType, "Error mapping DSS error to Python!");
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
                PyErr_SetString(PyExc_RuntimeError, "Unexpected number of elements returned by API (complex number).");
                return NULL;
            }
            return PyComplex_FromDoubles((*(double**)f->dataPtr)[0], (*(double**)f->dataPtr)[1]);
        case Signature_complex128:
            if (f->countPtr[0] & 1)
            {
                PyErr_SetString(PyExc_RuntimeError, "Unexpected number of elements returned by API (array of complex numbers).");
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
            PyErr_SetString(PyExc_TypeError, "Invalid type specified.");
            return NULL;
    }
    return result;
array_error:
    Py_XDECREF(result);
    return NULL;
}

static PyObject *AltDSS_PyStrGetter_call(AltDSS_PyStrGetterObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    PyObject *result = NULL;
    int argValue;
    char const* cstr;
    switch (f->funcArgSignature)
    {
        case Signature_one_int32:
            if (!PyArg_ParseTuple(args, "i", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (expected an integer value)");
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
    if (*f->errorPtr && f->parent->DSSExceptionType != Py_None)
    {
        if (ctx_Error_Get_Description != f->func)
        {
            const char *errorDesc = ctx_Error_Get_Description(f->dssCtx);
            int32_t num = *f->errorPtr;
            *f->errorPtr = 0;
            //TODO: check ref count here
            PyErr_SetObject(f->parent->DSSExceptionType, PyTuple_Pack(2, 
                PyLong_FromLong(num),
                PyUnicode_FromString(errorDesc)
            ));
            return NULL;
        }
        PyErr_SetString(f->parent->DSSExceptionType, "Error mapping DSS error to Python!");
        return NULL;
    }
    result = cstr ? PyUnicode_FromString(cstr) : PyUnicode_FromString("");
    return result;
}

static PyObject *AltDSS_PyStrListGetter_call(AltDSS_PyStrListGetterObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
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
        case Signature_one_int32:
            if (!PyArg_ParseTuple(args, "i", &argIntValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (expected an integer value)");
                return NULL;
            }
            ((func_ctx_strlist_int32_t)f->func)(f->dssCtx, &cstr_list, &count[0], argIntValue);
            break;
        case Signature_str:
            // TODO: use s# whenever possible
            if (!PyArg_ParseTuple(args, "s*", &argStrValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (expected either a string or bytes value)");
                return NULL;
            }
            ((func_ctx_strlist_pchar_t)f->func)(f->dssCtx, &cstr_list, &count[0], argStrValue);
            break;
        default:
            ((func_ctx_strlist_t)f->func)(f->dssCtx, &cstr_list, &count[0]);
            break;
    }

    if (*f->errorPtr && f->parent->DSSExceptionType != Py_None)
    {
        const char *errorDesc = ctx_Error_Get_Description(f->dssCtx);
        int32_t num = *f->errorPtr;
        *f->errorPtr = 0;
        //TODO: check ref count here
        PyErr_SetObject(f->parent->DSSExceptionType, PyTuple_Pack(2, 
            PyLong_FromLong(num),
            PyUnicode_FromString(errorDesc)
        ));
        DSS_Dispose_PPAnsiChar(&cstr_list, count[1]);
        return NULL;
    }

    result = PyList_New(count[0]);
    if (PyErr_Occurred())
    {
        DSS_Dispose_PPAnsiChar(&cstr_list, count[1]);
        return NULL;
    }

    for (i = 0, sptr = cstr_list; i < count[0]; ++i, ++sptr)
    {
        item = (*sptr) ? PyUnicode_FromString(*sptr) : PyUnicode_FromString("");
        if (PyErr_Occurred())
        {
            Py_DECREF(result);
            DSS_Dispose_PPAnsiChar(&cstr_list, count[1]);
            return NULL;
        }
        PyList_SetItem(result, i, item);
    }
    DSS_Dispose_PPAnsiChar(&cstr_list, count[1]);
    return result;
}


static PyTypeObject AltDSS_PyScalarGetterType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = ALTDSS_FAST_MODNAME ".AltDSS_PyScalarGetter",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API plain scalar (int32, float64, bool) functions, handling DSS errors"),
    .tp_basicsize = sizeof(AltDSS_PyScalarGetterObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSS_PyScalarGetter_init,
    .tp_call = ((PyCFunctionWithKeywords) AltDSS_PyScalarGetter_call),
};

static PyTypeObject AltDSS_PyStrGetterType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = ALTDSS_FAST_MODNAME ".AltDSS_PyStrGetter",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API plain str functions, handling DSS errors"),
    .tp_basicsize = sizeof(AltDSS_PyStrGetterObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSS_PyStrGetter_init,
    .tp_call = ((PyCFunctionWithKeywords) AltDSS_PyStrGetter_call),
};

static PyTypeObject AltDSS_PyStrListGetterType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = ALTDSS_FAST_MODNAME ".AltDSS_PyStrListGetter",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API function that returns an array of strings, handling DSS errors"),
    .tp_basicsize = sizeof(AltDSS_PyStrListGetterObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSS_PyStrListGetter_init,
    .tp_call = ((PyCFunctionWithKeywords) AltDSS_PyStrListGetter_call),
};

static PyTypeObject AltDSS_PyGRGetterType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = ALTDSS_FAST_MODNAME ".AltDSS_PyGRGetter",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API function that returns a numeric array, handling DSS errors and runtime settings"),
    .tp_basicsize = sizeof(AltDSS_PyGRGetterObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSS_PyGRGetter_init,
    .tp_call = ((PyCFunctionWithKeywords) AltDSS_PyGRGetter_call),
};


static PyMethodDef funcs[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef altdss_fast_def = {
    PyModuleDef_HEAD_INIT, 
    ALTDSS_FAST_MODNAME, 
    "A couple of faster string handling functions; CPython only.\n",
    -1,
    funcs
};

int AltDSS_Add_PyGetter(AltDSS_PyContextObject *self, int res_type, int args_type, void* c_func, PyObject **py_func, PyObject *setObj, PyObject *fakeLib, const char* fname);

static int AltDSS_PyContext_init(AltDSS_PyContextObject *self, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    char ***unused1;
    int32_t *unused2;
    PyObject* setObj = NULL;
    PyObject* fakeLib = NULL;
    if (sizeof(unsigned long long) < sizeof(void*))
    {
        PyErr_SetString(PyExc_TypeError, "Unexpected integer sizes!");
        return -1;
    }

    unsigned long long dssCtx, settingsPtr;
    if ((!PyArg_ParseTuple(args, "KKOOO", &dssCtx, &settingsPtr, &self->DSSExceptionType, &setObj, &fakeLib)) || !PyObject_IsInstance(setObj, (PyObject*) &PySet_Type))
    {
        PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyContext initialization");
        return -1;
    }
    
    self->dssCtx = (void*) dssCtx;
    self->settingsPtr = (int32_t*) settingsPtr;
    self->errorPtr = ctx_Error_Get_NumberPtr(self->dssCtx);
    
    ctx_DSS_GetGRPointers(self->dssCtx,
        &unused1,
        &self->dataPtr_pdouble,
        &self->dataPtr_pinteger,
        &self->dataPtr_pbyte,
        &unused2,
        &self->countPtr_pdouble,
        &self->countPtr_pinteger,
        &self->countPtr_pbyte
    );
    Py_INCREF(setObj);
    Py_INCREF(fakeLib);
    Py_INCREF(self->DSSExceptionType);

#include "./_fast_py_init.inc.c"

    Py_DECREF(setObj);
    Py_DECREF(fakeLib);
    return 0;
ERROR_INIT:
    Py_DECREF(setObj);
    Py_DECREF(fakeLib);
    Py_DECREF(self->DSSExceptionType);
    self->DSSExceptionType = NULL;
    PyErr_SetString(PyExc_RuntimeError, "Error initializing AltDSS C-API function handlers!");
    return -1;
}


static PyObject *AltDSS_PyContext_set_exc_type(AltDSS_PyContextObject *self, PyObject *arg)
{
    self->DSSExceptionType = arg;
    Py_INCREF(arg);
    return Py_None;
}

static PyMethodDef AltDSS_PyContext_methods[] = {
    //{"__call__", (PyCFunction) AltDSS_PyStrGetter_call, METH_NOARGS, "Call the low-level function, mapping the result string to Python, while checking for DSS errors."},
    {"set_exc_type", (PyCFunction) AltDSS_PyContext_set_exc_type, METH_O, "Set the exception class to raise on DSS errors. If None, exceptions are disabled."},
    {NULL}
};

static PyMemberDef AltDSS_PyContext_members[] = {
#include "./_fast_py_members.inc.c"
    {NULL}
};

static PyTypeObject AltDSS_PyContextType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = ALTDSS_FAST_MODNAME ".AltDSS_PyContext",
    .tp_doc = PyDoc_STR("Wraps a subset of the AltDSS C-API functions, handling DSS errors"),
    .tp_basicsize = sizeof(AltDSS_PyContextObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSS_PyContext_init,
    // .tp_call = AltDSS_PyContext_call,
    .tp_methods = AltDSS_PyContext_methods,
    .tp_members = AltDSS_PyContext_members,
};

PyMODINIT_FUNC ALTDSS_FAST_MODINIT()
{
    PyObject *m;

    // Sanity checks
    if (sizeof(unsigned long long) < sizeof(void*))
    {
        PyErr_SetString(PyExc_TypeError, "Unexpected integer sizes (unsigned long long)");
        return NULL;
    }
    if (sizeof(long) < sizeof(int32_t))
    {
        PyErr_SetString(PyExc_TypeError, "Unexpected integer sizes (int32_t)");
        return NULL;
    }

    import_array();

    if (
        PyType_Ready(&AltDSS_PyStrGetterType) < 0 
        || PyType_Ready(&AltDSS_PyStrListGetterType) < 0
        || PyType_Ready(&AltDSS_PyGRGetterType) < 0
        || PyType_Ready(&AltDSS_PyScalarGetterType) < 0
        || PyType_Ready(&AltDSS_PyContextType) < 0
    )
    {
        return NULL;
    }

    m = PyModule_Create(&altdss_fast_def);
    if (m == NULL)
    {
        return NULL;
    }

    Py_INCREF(&AltDSS_PyContextType);
    if (PyModule_AddObject(m, "AltDSS_PyContext", (PyObject *) &AltDSS_PyContextType) < 0)
    {
        goto ERROR0;
    }
    Py_INCREF(&AltDSS_PyStrGetterType);
    if (PyModule_AddObject(m, "AltDSS_PyStrGetter", (PyObject *) &AltDSS_PyStrGetterType) < 0)
    {
        goto ERROR1;
    }
    Py_INCREF(&AltDSS_PyStrListGetterType);
    if (PyModule_AddObject(m, "AltDSS_PyStrListGetter", (PyObject *) &AltDSS_PyStrListGetterType) < 0)
    {
        goto ERROR2;
    }
    Py_INCREF(&AltDSS_PyGRGetterType);
    if (PyModule_AddObject(m, "AltDSS_PyGRGetter", (PyObject *) &AltDSS_PyGRGetterType) < 0)
    {
        goto ERROR3;
    }
    Py_INCREF(&AltDSS_PyScalarGetterType);
    if (PyModule_AddObject(m, "AltDSS_PyScalarGetter", (PyObject *) &AltDSS_PyScalarGetterType) < 0)
    {
        goto ERROR4;
    }

    return m;

ERROR4:
    Py_DECREF(&AltDSS_PyScalarGetterType);
ERROR3:
    Py_DECREF(&AltDSS_PyGRGetterType);
ERROR2:
    Py_DECREF(&AltDSS_PyStrListGetterType);
ERROR1:
    Py_DECREF(&AltDSS_PyStrGetterType);
ERROR0:
    Py_DECREF(&AltDSS_PyContextType);
    Py_DECREF(m);
    return NULL;
}


int AltDSS_PyStrListGetter_cinit(AltDSS_PyStrListGetterObject* f, AltDSS_PyContextObject *alt_py_ctx, int res_type, int args_type, void* c_func)
{
    void* ctx = alt_py_ctx->dssCtx;

    if (res_type != Signature_str_list)
    {
        f->dssCtx = NULL;
        f->func = NULL;
        return 0;
    }

    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = args_type;
    f->resType = res_type;
    return 1;
}

int AltDSS_PyScalarGetter_cinit(AltDSS_PyScalarGetterObject* f, AltDSS_PyContextObject *alt_py_ctx, int res_type, int args_type, void* c_func)
{
    void* ctx = alt_py_ctx->dssCtx;

    if (res_type != Signature_one_int32 && 
        res_type != Signature_one_float64 && 
        res_type != Signature_one_bool)
    {
        f->dssCtx = NULL;
        f->func = NULL;
        return 0;
    }

    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = args_type;
    f->resType = res_type;
    return 1;
}

int AltDSS_PyStrGetter_cinit(AltDSS_PyStrGetterObject* f, AltDSS_PyContextObject *alt_py_ctx, int res_type, int args_type, void* c_func)
{
    void* ctx = alt_py_ctx->dssCtx;

    if (res_type != Signature_str)
    {
        f->dssCtx = NULL;
        f->func = NULL;
        return 0;
    }

    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = args_type;
    f->resType = res_type;
    return 1;
}

int AltDSS_PyGRGetter_cinit(AltDSS_PyGRGetterObject* f, AltDSS_PyContextObject *alt_py_ctx, int resType, int argsType, void* c_func)
{
    void* ctx = alt_py_ctx->dssCtx;

    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = argsType;
    f->resType = resType;
    switch (resType)
    {
        case Signature_complex128:
        case Signature_one_complex128:
        case Signature_float64:
            f->dataPtr = (void*) alt_py_ctx->dataPtr_pdouble;
            f->countPtr = alt_py_ctx->countPtr_pdouble;
            return 1;
        case Signature_int32:
            f->dataPtr = (void*)alt_py_ctx->dataPtr_pinteger;
            f->countPtr = alt_py_ctx->countPtr_pinteger;
            return 1;
        case Signature_int8:
            f->dataPtr = (void*)alt_py_ctx->dataPtr_pbyte;
            f->countPtr = alt_py_ctx->countPtr_pbyte;
            return 1;
        default:
            f->dssCtx = NULL;
            f->func = NULL;
            return 0;
    }
}

int AltDSS_Add_PyGetter(AltDSS_PyContextObject *self, int res_type, int args_type, void* c_func, PyObject **py_func, PyObject *setObj, PyObject *fakeLib, const char* fname)
{
    PyObject* key = NULL;
    switch (res_type)
    {
        case Signature_str_list:
            *py_func = (PyObject*) PyObject_New(AltDSS_PyStrListGetterObject, &AltDSS_PyStrListGetterType);
            if ((*py_func) == NULL)
            {
                goto ADD_FUNC_ERROR;
            }
            AltDSS_PyStrListGetter_cinit((AltDSS_PyStrListGetterObject*) *py_func, self, res_type, args_type, c_func);
            break;
        case Signature_str:
            *py_func = (PyObject*) PyObject_New(AltDSS_PyStrGetterObject, &AltDSS_PyStrGetterType);
            if ((*py_func) == NULL)
            {
                goto ADD_FUNC_ERROR;
            }
            AltDSS_PyStrGetter_cinit((AltDSS_PyStrGetterObject*) *py_func, self, res_type, args_type, c_func);
            break;
        case Signature_one_float64:
        case Signature_one_int32:
        case Signature_one_bool:
            *py_func = (PyObject*) PyObject_New(AltDSS_PyScalarGetterObject, &AltDSS_PyScalarGetterType);
            if ((*py_func) == NULL)
            {
                goto ADD_FUNC_ERROR;
            }
            AltDSS_PyScalarGetter_cinit((AltDSS_PyScalarGetterObject*) *py_func, self, res_type, args_type, c_func);
            break;
        case Signature_complex128:
        case Signature_float64:
        case Signature_int32:
        case Signature_int8:
            *py_func = (PyObject*) PyObject_New(AltDSS_PyGRGetterObject, &AltDSS_PyGRGetterType);
            if ((*py_func) == NULL)
            {
                goto ADD_FUNC_ERROR;
            }
            AltDSS_PyGRGetter_cinit((AltDSS_PyGRGetterObject*) *py_func, self, res_type, args_type, c_func);
            break;
        default:
            goto ADD_FUNC_ERROR;
    }

    key = PyUnicode_FromString(fname);
    Py_INCREF(key);
    if (PyObject_SetAttr(fakeLib, key, *py_func))
    {
        Py_DECREF(*py_func);
        goto ADD_FUNC_ERROR;
    }

    if (PySet_Add(setObj, key))
    {
        Py_DECREF(*py_func);
        goto ADD_FUNC_ERROR;
    }
    
    return 1;
ADD_FUNC_ERROR:
    *py_func = NULL;
    Py_DECREF(key);
    return 0;
}
