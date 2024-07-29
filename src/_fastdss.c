// This is a C extension that contains a few faster alternatives for a subset
// of functions from AltDSS/DSS C-API. The rest of the functions are handled
// via CFFI.
// Originally written by Paulo Meira for dss_python_backend, to be 
// used in DSS-Python, OpenDSSDirect.py and AltDSS-Python.

// TODO: PyLong_FromVoidPtr and PyLong_AsVoidPtr could be used?
// TODO: enums in int32 and one_int32 results, e.g. LoadModels

#define PY_SSIZE_T_CLEAN
// #define Py_LIMITED_API 0x03070000
#include <string.h>
#include <Python.h>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/ndarrayobject.h"
#include "dss_capi_ctx.h"

// #ifndef PyList_SET_ITEM
// #define PyList_SET_ITEM PyList_SetItem 
// #endif

typedef int32_t (*func_i32_ctx_i32)(const void* ctx, int32_t value);
typedef int32_t (*func_i32_ctx_str)(const void* ctx, const char* value);
typedef int32_t (*func_i32_ctx)(const void* ctx);

typedef double (*func_f64_ctx_i32)(const void* ctx, int32_t value);
typedef double (*func_f64_ctx_str)(const void* ctx, const char* value);
typedef double (*func_f64_ctx)(const void* ctx);

typedef uint16_t (*func_b16_ctx_i32)(const void* ctx, int32_t value);
typedef uint16_t (*func_b16_ctx_i32_i32)(const void* ctx, int32_t value, int32_t value2);
typedef uint16_t (*func_b16_ctx_str)(const void* ctx, const char* value);
typedef uint16_t (*func_b16_ctx)(const void* ctx);

typedef const char* (*func_str_ctx)(const void* ctx);
typedef const char* (*func_str_ctx_i32)(const void* ctx, int32_t value);
typedef void (*func_void_ctx_strs)(const void* ctx, char*** ResultPtr, int32_t* ResultDims);
typedef void (*func_void_ctx_strs_i32)(const void* ctx, char*** ResultPtr, int32_t* ResultDims, int32_t value);
typedef void (*func_void_ctx_strs_str)(const void* ctx, char*** ResultPtr, int32_t* ResultDims, const char* value);
typedef void (*gr_func_void_ctx)(const void* ctx);
typedef void (*gr_func_void_ctx_b16)(const void* ctx, uint16_t value);
typedef void (*gr_func_void_ctx_i32)(const void* ctx, int32_t value);
typedef void (*gr_func_void_ctx_f64_f64_i32)(const void* ctx, double f1, double f2, int32_t value);

typedef void (*func_void_ctx_i32)(const void* ctx, int32_t value);
typedef void (*func_void_ctx_i32_i32)(const void* ctx, int32_t value, int32_t value2);
typedef void (*func_void_ctx_f64)(const void* ctx, double value);
typedef void (*func_void_ctx_b16)(const void* ctx, uint16_t value);
typedef void (*func_void_ctx_str)(const void* ctx, const char* value);
typedef void (*func_void_ctx)(const void* ctx);

enum {
    fastdss_types_void = 0,
    fastdss_types_b16,
    fastdss_types_f32,
    fastdss_types_f64,
    fastdss_types_f64_f64_i32,
    fastdss_types_gr_f64s,
    fastdss_types_gr_i32s,
    fastdss_types_gr_i8s,
    fastdss_types_gr_z128,
    fastdss_types_gr_z128s,
    fastdss_types_i32,
    fastdss_types_i32_i32,
    fastdss_types_str,
    fastdss_types_strs,
    fastdss_types_z64,
};

enum FastDSSSettings {
    FastDSSSettings_UseExceptions = 1 << 0,
    FastDSSSettings_AdvancedTypes = 1 << 1,
    FastDSSSettings_ODDPyStrings = 1 << 2,
    FastDSSSettings_UseLists = 1 << 3,
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
    char const* fname;
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
    char const* fname;
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
    char const* fname;
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
    char const* fname;
} AltDSS_PyScalarSetterObject;

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
    char const* fname;

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

    #include "./_fastdss_struct_members.inc.c"
} AltDSS_PyContextObject;

typedef struct {
    int resType;
    int argType;
    void* c_func;
    size_t attrOffset;
    char const* fname;
} FastDSSFuncInfo;

static int AltDSS_PyScalarSetter_init(AltDSS_PyScalarSetterObject *f, PyObject *Py_UNUSED(args_ignored), PyObject *Py_UNUSED(kwargs_ignored))
{
    f->parent = NULL;
    f->dssCtx = NULL;
    f->func = NULL;
    return 0;
}

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

static int AltDSS_PyStrGetter_init(AltDSS_PyStrGetterObject *f, PyObject *Py_UNUSED(args_ignored), PyObject *Py_UNUSED(kwargs_ignored))
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

static PyObject *AltDSS_PyScalarSetter_call(AltDSS_PyScalarSetterObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    PyObject* result = NULL;
    int cval_int, cval_int2;
    double cval_float64;
    char const *cstr = NULL;
    Py_ssize_t cstr_size = 0;
    
    switch (f->funcArgSignature)
    {
        case fastdss_types_i32:
            if (!PyArg_ParseTuple(args, "i", &cval_int))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarSetter call (expected an integer value)");
                return NULL;
            }
            ((func_void_ctx_i32)f->func)(f->dssCtx, cval_int);
            break;
        case fastdss_types_i32_i32:
            if (!PyArg_ParseTuple(args, "ii", &cval_int, &cval_int2))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarSetter call (expected two integer values)");
                return NULL;
            }
            ((func_void_ctx_i32_i32)f->func)(f->dssCtx, cval_int, cval_int2);
            break;
        case fastdss_types_f64:
            if (!PyArg_ParseTuple(args, "d", &cval_float64))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarSetter call (expected a float64 value)");
                return NULL;
            }
            ((func_void_ctx_f64)f->func)(f->dssCtx, cval_float64);
            break;
        case fastdss_types_b16:
            if (!PyArg_ParseTuple(args, "p", &cval_int))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarSetter call (expected a boolean value)");
                return NULL;
            }
            ((func_void_ctx_b16)f->func)(f->dssCtx, cval_int ? (uint16_t)-1 : (uint16_t)0);
            break;
        case fastdss_types_str:
            if (!PyArg_ParseTuple(args, "s#", &cstr, &cstr_size))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarSetter call (expected a str or bytes value)");
                return NULL;
            }
            ((func_void_ctx_str)f->func)(f->dssCtx, cstr);
            break;
        case fastdss_types_void:
            ((func_void_ctx)f->func)(f->dssCtx);
            break;
        default:
            PyErr_SetString(PyExc_TypeError, "Invalid call signature");
            return NULL;
    }

    if (*f->errorPtr && ((*f->settingsPtr) & FastDSSSettings_UseExceptions) && f->parent->DSSExceptionType != Py_None)
        {
            const char *errorDesc = ctx_Error_Get_Description(f->dssCtx);
            int32_t num = *f->errorPtr;
            *f->errorPtr = 0;
            PyErr_SetObject(f->parent->DSSExceptionType, PyTuple_Pack(2, 
                PyLong_FromLong(num),
                PyUnicode_FromString(errorDesc)
            ));
        return NULL;
    }
    result = Py_None;
    Py_INCREF(result);
    return result;
}

static PyObject *AltDSS_PyScalarGetter_call(AltDSS_PyScalarGetterObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    PyObject *result = NULL;
    int argValue, argValue2;
    int32_t cval_int32 = -1;
    double cval_float64 = -1;
    char const *cstr = NULL;
    Py_ssize_t cstr_size = 0;

    switch (f->funcArgSignature)
    {
        case fastdss_types_i32_i32:
            if (!PyArg_ParseTuple(args, "ii", &argValue, &argValue2))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarGetter call (expected two integer values)");
                return NULL;
            }
            break;
        case fastdss_types_i32:
            if (!PyArg_ParseTuple(args, "i", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarGetter call (expected an integer value)");
                return NULL;
            }
            break;
        case fastdss_types_str:
            if (!PyArg_ParseTuple(args, "s#", &cstr, &cstr_size))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyScalarGetter call (expected a str or bytes value)");
                return NULL;
            }
        case fastdss_types_void:
            break;
        default:
            PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (unknown signature)");
            return NULL;
    }

    switch (f->resType)
    {
        case fastdss_types_b16:
        switch (f->funcArgSignature)
        {
            case fastdss_types_i32_i32:
                cval_int32 = ((func_b16_ctx_i32_i32)f->func)(f->dssCtx, argValue, argValue2);
                break;
            case fastdss_types_i32:
                cval_int32 = ((func_b16_ctx_i32)f->func)(f->dssCtx, argValue);
                break;
            case fastdss_types_str:
                cval_int32 = ((func_b16_ctx_str)f->func)(f->dssCtx, cstr);
                break;
            case fastdss_types_void:
                cval_int32 = ((func_b16_ctx)f->func)(f->dssCtx);
                break;
            default:
                PyErr_SetString(PyExc_TypeError, "Internal error: unknown signature");
                return NULL;
        }
        break;
        case fastdss_types_i32:
        switch (f->funcArgSignature)
        {
            case fastdss_types_i32:
                cval_int32 = ((func_i32_ctx_i32)f->func)(f->dssCtx, argValue);
                break;
            case fastdss_types_str:
                cval_int32 = ((func_i32_ctx_str)f->func)(f->dssCtx, cstr);
                break;
            case fastdss_types_void:
                cval_int32 = ((func_i32_ctx)f->func)(f->dssCtx);
                break;
            default:
                PyErr_SetString(PyExc_TypeError, "Internal error: unknown signature");
                return NULL;
        }
        break;
        case fastdss_types_f64:
        switch (f->funcArgSignature)
        {
            case fastdss_types_i32:
                cval_float64 = ((func_f64_ctx_i32)f->func)(f->dssCtx, argValue);
                break;
            case fastdss_types_str:
                cval_float64 = ((func_f64_ctx_str)f->func)(f->dssCtx, cstr);
                break;
            case fastdss_types_void:
                cval_float64 = ((func_f64_ctx)f->func)(f->dssCtx);
                break;
            default:
                PyErr_SetString(PyExc_TypeError, "Internal error: unknown signature");
                return NULL;
        }
        break;
    }

    if (*f->errorPtr && ((*f->settingsPtr) & FastDSSSettings_UseExceptions) && f->parent->DSSExceptionType != Py_None)
        {
            const char *errorDesc = ctx_Error_Get_Description(f->dssCtx);
            int32_t num = *f->errorPtr;
            *f->errorPtr = 0;
            PyErr_SetObject(f->parent->DSSExceptionType, PyTuple_Pack(2, 
                PyLong_FromLong(num),
                PyUnicode_FromString(errorDesc)
            ));
        return NULL;
    }

    switch (f->resType)
    {
        case fastdss_types_b16:
            result = (cval_int32 ? Py_True : Py_False);
            Py_INCREF(result);
            return result;
        case fastdss_types_i32:
            return PyLong_FromLong(cval_int32);
        case fastdss_types_f64:
            return PyFloat_FromDouble(cval_float64);
    }
    return NULL;
}

static PyObject *AltDSS_PyGRGetter_call(AltDSS_PyGRGetterObject *f, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    PyObject *result = NULL;
    PyObject *item = NULL;
    double float64Arg1, float64Arg2;
    int argValue = 0;
    int32_t resType = f->resType;
    const int32_t settings = *f->settingsPtr;
    int nd = 1;
    int nitems, i;
    npy_intp dims[2];
    void *data;
    double *dblPtr;
    int32_t *i32Ptr;
    int8_t *i8Ptr;

    switch (f->funcArgSignature)
    {
        case fastdss_types_f64_f64_i32:
            if (!PyArg_ParseTuple(args, "ddi", &float64Arg1, &float64Arg2, &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyGRGetter call (expected float, float, integer arguments)");
                return NULL;
            }
            ((gr_func_void_ctx_f64_f64_i32)f->func)(f->dssCtx, float64Arg1, float64Arg2, argValue);
            break;
        case fastdss_types_i32:
            if (!PyArg_ParseTuple(args, "i", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyGRGetter call (expected an integer value)");
                return NULL;
            }
            ((gr_func_void_ctx_i32)f->func)(f->dssCtx, argValue);
            break;
        case fastdss_types_b16:
            if (!PyArg_ParseTuple(args, "p", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyGRSetter call (expected a boolean value)");
                return NULL;
            }
            ((gr_func_void_ctx_b16)f->func)(f->dssCtx, argValue ? (uint16_t)-1 : (uint16_t)0);
            break;
        default:
            ((gr_func_void_ctx)f->func)(f->dssCtx);
            break;
    }
    if (*f->errorPtr && ((*f->settingsPtr) & FastDSSSettings_UseExceptions) && f->parent->DSSExceptionType != Py_None)
        {
            const char *errorDesc = ctx_Error_Get_Description(f->dssCtx);
            int32_t num = *f->errorPtr;
            *f->errorPtr = 0;
            PyErr_SetObject(f->parent->DSSExceptionType, PyTuple_Pack(2, 
                PyLong_FromLong(num),
                PyUnicode_FromString(errorDesc)
            ));
        return NULL;
    }

    nitems = f->countPtr[0];
    if ((f->countPtr[2] == 0))
    {
        dims[0] = nitems;
        if (resType == fastdss_types_gr_z128s)
        {
            resType = fastdss_types_gr_f64s;
        }
    }
    else
    {
        nd = 2;
        dims[0] = f->countPtr[2];
        dims[1] = f->countPtr[3];
        if (resType == fastdss_types_gr_z128s)
    {
        nitems /= 2;
        }
    }

    if (!(settings & FastDSSSettings_UseLists))
    {
        switch (resType)
        {
            case fastdss_types_gr_z128:
                if (f->countPtr[0] != 2)
                {
                    PyErr_SetString(PyExc_RuntimeError, "Unexpected number of elements returned by API (complex number).");
                    return NULL;
                }
                return PyComplex_FromDoubles((*(double**)f->dataPtr)[0], (*(double**)f->dataPtr)[1]);
            case fastdss_types_gr_z128s:
                if (f->countPtr[0] & 1)
                {
                    PyErr_SetString(PyExc_RuntimeError, "Unexpected number of elements returned by API (array of complex numbers).");
                    return NULL;
                }
                result = PyArray_SimpleNew(nd, dims, NPY_COMPLEX128);
                if (result == NULL)
                {
                    return NULL;
                }
                data = PyArray_DATA((PyArrayObject*) result);
                if (data == NULL)
                    goto array_error;
                memcpy(data, *(double**)f->dataPtr, 2 * sizeof(double) * nitems);
                return result;
            case fastdss_types_gr_f64s:
                result = PyArray_SimpleNew(nd, dims, NPY_FLOAT64);
                if (result == NULL)
                {
                    return NULL;
                }
                data = PyArray_DATA((PyArrayObject*) result);
                if (data == NULL)
                    goto array_error;
                memcpy(data, *(double**)f->dataPtr, sizeof(double) * nitems);
                return result;
            // case fastdss_types_f32:
            //     result = PyArray_SimpleNew(nd, dims, NPY_FLOAT32);
            //     memcpy(data, f->dataPtr[0], *(float**)f->dataPtr, sizeof(float) * nitems);
            //     data = PyArray_DATA(result);
            //     return result;
            case fastdss_types_gr_i32s:
                result = PyArray_SimpleNew(nd, dims, NPY_INT32);
                if (result == NULL)
                {
                    return NULL;
                }
                data = PyArray_DATA((PyArrayObject*) result);
                if (data == NULL)
                    goto array_error;
                memcpy(data, *(int32_t**)f->dataPtr, sizeof(int32_t) * nitems);
                return result;
            case fastdss_types_gr_i8s:
                result = PyArray_SimpleNew(nd, dims, NPY_INT8);
                if (result == NULL)
                {
                    return NULL;
                }
                data = PyArray_DATA((PyArrayObject*) result);
                if (data == NULL)
                    goto array_error;
                memcpy(data, *(int8_t**)f->dataPtr, sizeof(int8_t) * nitems);
                return result;
            default:
                PyErr_SetString(PyExc_TypeError, "Invalid type specified.");
                return NULL;
        }
    }

    // Duplicated from above, but using lists
    switch (resType)
    {
        case fastdss_types_gr_z128:
            if (f->countPtr[0] != 2)
            {
                PyErr_SetString(PyExc_RuntimeError, "Unexpected number of elements returned by API (complex number).");
                return NULL;
            }
            return PyComplex_FromDoubles((*(double**)f->dataPtr)[0], (*(double**)f->dataPtr)[1]);
        case fastdss_types_gr_z128s:
            if (f->countPtr[0] & 1)
            {
                PyErr_SetString(PyExc_RuntimeError, "Unexpected number of elements returned by API (array of complex numbers).");
                return NULL;
            }
            result = PyList_New(nitems);
            if (result == NULL)
            {
                return NULL;
            }
            dblPtr = *(double**)f->dataPtr;
            for (i = 0; i < nitems; ++i, dblPtr += 2)
            {
                item = PyComplex_FromDoubles(dblPtr[0], dblPtr[1]);
                if (item == NULL)
                {
                    goto array_error;
                }
                PyList_SET_ITEM(result, i, item);
            }
            return result;
        case fastdss_types_gr_f64s:
            result = PyList_New(nitems);
            if (result == NULL)
            {
                return NULL;
            }
            dblPtr = *(double**)f->dataPtr;
            for (i = 0; i < nitems; ++i, ++dblPtr)
            {
                item = PyFloat_FromDouble(*dblPtr);
                if (item == NULL)
                {
                    goto array_error;
                }
                PyList_SET_ITEM(result, i, item);
            }
            return result;
        // case fastdss_types_f32:
        //     result = PyArray_SimpleNew(nd, dims, NPY_FLOAT32);
        //     memcpy(data, f->dataPtr[0], *(float**)f->dataPtr, sizeof(float) * nitems);
        //     data = PyArray_DATA(result);
        //     return result;
        case fastdss_types_gr_i32s:
            result = PyList_New(nitems);
            if (result == NULL)
            {
                return NULL;
            }
            i32Ptr = *(int32_t**)f->dataPtr;
            for (i = 0; i < nitems; ++i, ++i32Ptr)
            {
                item = PyLong_FromLong(*i32Ptr);
                if (item == NULL)
                {
                    goto array_error;
                }
                PyList_SET_ITEM(result, i, item);
            }
            return result;
        case fastdss_types_gr_i8s:
            result = PyList_New(nitems);
            if (result == NULL)
            {
                return NULL;
            }
            i8Ptr = *(int8_t**)f->dataPtr;
            for (i = 0; i < nitems; ++i, ++i8Ptr)
            {
                item = PyLong_FromLong(*i8Ptr);
                if (item == NULL)
                {
                    goto array_error;
                }
                PyList_SET_ITEM(result, i, item);
            }
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
        case fastdss_types_i32:
            if (!PyArg_ParseTuple(args, "i", &argValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (expected an integer value)");
                return NULL;
            }
            cstr = ((func_str_ctx_i32)f->func)(f->dssCtx, argValue);
            break;
        default:
            cstr = ((func_str_ctx)f->func)(f->dssCtx);
            break;
    }
    //TODO: for Alt functions, we will need to dispose the C string later, 
    // or take ownership of the pointer.
    if (*f->errorPtr && ((*f->settingsPtr) & FastDSSSettings_UseExceptions) && f->parent->DSSExceptionType != Py_None)
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
    char const *cstr = NULL;
    Py_ssize_t cstr_size = 0;
    char** sptr = NULL;
    int32_t count[4] = {0, 0, 0, 0};
    int32_t i;
    int argIntValue;
    const int32_t settings = *f->settingsPtr;

    switch (f->funcArgSignature)
    {
        case fastdss_types_i32:
            if (!PyArg_ParseTuple(args, "i", &argIntValue))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (expected an integer value)");
                return NULL;
            }
            ((func_void_ctx_strs_i32)f->func)(f->dssCtx, &cstr_list, &count[0], argIntValue);
            break;
        case fastdss_types_str:
            if (!PyArg_ParseTuple(args, "s#", &cstr, &cstr_size))
            {
                PyErr_SetString(PyExc_TypeError, "Invalid arguments on AltDSS_PyStrGetter call (expected either a string or bytes value)");
                return NULL;
            }
            ((func_void_ctx_strs_str)f->func)(f->dssCtx, &cstr_list, &count[0], cstr);
            break;
        default:
            ((func_void_ctx_strs)f->func)(f->dssCtx, &cstr_list, &count[0]);
            break;
    }

    if (*f->errorPtr && ((*f->settingsPtr) & FastDSSSettings_UseExceptions) && f->parent->DSSExceptionType != Py_None)
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

    if ((settings & FastDSSSettings_ODDPyStrings) && (count[0] == 1))
    {
        cstr = cstr_list[0];
        if ((cstr == NULL) || (cstr[0] == 0))
        {
            count[0] = 0;
        }
        else if ((strnlen(cstr, 5) == 4) && (
            (cstr[0] == 'n' || cstr[0] == 'N') &&
            (cstr[1] == 'o' || cstr[1] == 'O') &&
            (cstr[2] == 'n' || cstr[2] == 'N') &&
            (cstr[3] == 'e' || cstr[3] == 'E')
        ))
        {
            count[0] = 0;
        }
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
        PyList_SET_ITEM(result, i, item);
    }
    DSS_Dispose_PPAnsiChar(&cstr_list, count[1]);
    return result;
}


static PyTypeObject AltDSS_PyScalarGetterType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = ALTDSS_FAST_MODNAME ".AltDSS_PyScalarGetter",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API plain scalar (int32, float64, bool) getter functions, handling DSS errors"),
    .tp_basicsize = sizeof(AltDSS_PyScalarGetterObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSS_PyScalarGetter_init,
    .tp_call = ((PyCFunctionWithKeywords) AltDSS_PyScalarGetter_call),
};

static PyTypeObject AltDSS_PyScalarSetterType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = ALTDSS_FAST_MODNAME ".AltDSS_PyScalarSetter",
    .tp_doc = PyDoc_STR("Wrap an AltDSS C-API plain scalar (int32, float64, bool) setter functions, handling DSS errors"),
    .tp_basicsize = sizeof(AltDSS_PyScalarSetterObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) AltDSS_PyScalarSetter_init,
    .tp_call = ((PyCFunctionWithKeywords) AltDSS_PyScalarSetter_call),
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

int AltDSS_Add_PyFunc(AltDSS_PyContextObject *self, FastDSSFuncInfo* finfo, PyObject *setObj, PyObject *fakeLib);

#include "./_fastdss_func_info.inc.c"

static int AltDSS_PyContext_init(AltDSS_PyContextObject *self, PyObject *args, PyObject *Py_UNUSED(kwargs_ignored))
{
    char ***unused1;
    int32_t *unused2;
    PyObject* setObj = NULL;
    PyObject* fakeLib = NULL;
    FastDSSFuncInfo* finfo = NULL;

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

    finfo = &info[0];
    while (finfo->c_func != NULL)
    {
        // printf("INFO: function %s\n", finfo->fname);
        if (!AltDSS_Add_PyFunc(self, finfo, setObj, fakeLib))
        {
            goto ERROR_INIT;
        }
        ++finfo;
    }

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
    PyObject* result = Py_None;
    self->DSSExceptionType = arg;
    Py_INCREF(arg);
    Py_INCREF(result);
    return result;
}

static PyMethodDef AltDSS_PyContext_methods[] = {
    //{"__call__", (PyCFunction) AltDSS_PyStrGetter_call, METH_NOARGS, "Call the low-level function, mapping the result string to Python, while checking for DSS errors."},
    {"set_exc_type", (PyCFunction) AltDSS_PyContext_set_exc_type, METH_O, "Set the exception class to raise on DSS errors. If None, exceptions are disabled."},
    {NULL}
};

#include "./_fastdss_py_members.inc.c"

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
        || PyType_Ready(&AltDSS_PyScalarSetterType) < 0
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

    Py_INCREF(&AltDSS_PyScalarSetterType);
    if (PyModule_AddObject(m, "AltDSS_PyScalarSetter", (PyObject *) &AltDSS_PyScalarSetterType) < 0)
    {
        goto ERROR5;
    }

    return m;

ERROR5:
    Py_DECREF(&AltDSS_PyScalarSetterType);
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


int AltDSS_PyStrListGetter_cinit(AltDSS_PyStrListGetterObject* f, AltDSS_PyContextObject *alt_py_ctx, FastDSSFuncInfo* finfo)
{
    if (finfo->resType != fastdss_types_strs)
    {
        f->dssCtx = NULL;
        f->func = NULL;
        return 0;
    }

    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = finfo->c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = finfo->argType;
    f->resType = finfo->resType;
    f->fname = finfo->fname;
    return 1;
}

int AltDSS_PyScalarSetter_cinit(AltDSS_PyScalarSetterObject* f, AltDSS_PyContextObject *alt_py_ctx, FastDSSFuncInfo* finfo)
{
    if ((
        finfo->argType != fastdss_types_i32_i32 &&
        finfo->argType != fastdss_types_i32 && 
        finfo->argType != fastdss_types_f64 && 
        finfo->argType != fastdss_types_b16 &&
        finfo->argType != fastdss_types_void &&
        finfo->argType != fastdss_types_str)
        || (finfo->resType != fastdss_types_void)
        )
    {
        f->dssCtx = NULL;
        f->func = NULL;
        return 0;
    }

    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = finfo->c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = finfo->argType;
    f->resType = finfo->resType;
    f->fname = finfo->fname;
    return 1;
}

int AltDSS_PyScalarGetter_cinit(AltDSS_PyScalarGetterObject* f, AltDSS_PyContextObject *alt_py_ctx, FastDSSFuncInfo* finfo)
{
    if (finfo->resType != fastdss_types_i32 && 
        finfo->resType != fastdss_types_f64 && 
        finfo->resType != fastdss_types_b16)
    {
        f->dssCtx = NULL;
        f->func = NULL;
        return 0;
    }

    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = finfo->c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = finfo->argType;
    f->resType = finfo->resType;
    f->fname = finfo->fname;
    return 1;
}

int AltDSS_PyStrGetter_cinit(AltDSS_PyStrGetterObject* f, AltDSS_PyContextObject *alt_py_ctx, FastDSSFuncInfo* finfo)
{
    if (finfo->resType != fastdss_types_str)
    {
        f->dssCtx = NULL;
        f->func = NULL;
        return 0;
    }

    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = finfo->c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = finfo->argType;
    f->resType = finfo->resType;
    f->fname = finfo->fname;
    return 1;
}

int AltDSS_PyGRGetter_cinit(AltDSS_PyGRGetterObject* f, AltDSS_PyContextObject *alt_py_ctx, FastDSSFuncInfo* finfo)
{
    f->parent = alt_py_ctx;
    f->dssCtx = alt_py_ctx->dssCtx;
    f->errorPtr = alt_py_ctx->errorPtr;
    f->func = finfo->c_func;
    f->settingsPtr = alt_py_ctx->settingsPtr;
    f->funcArgSignature = finfo->argType;
    f->resType = finfo->resType;
    f->fname = finfo->fname;
    switch (finfo->resType)
    {
        case fastdss_types_gr_z128s:
        case fastdss_types_gr_z128:
        case fastdss_types_gr_f64s:
            f->dataPtr = (void*) alt_py_ctx->dataPtr_pdouble;
            f->countPtr = alt_py_ctx->countPtr_pdouble;
            return 1;
        case fastdss_types_gr_i32s:
            f->dataPtr = (void*)alt_py_ctx->dataPtr_pinteger;
            f->countPtr = alt_py_ctx->countPtr_pinteger;
            return 1;
        case fastdss_types_gr_i8s:
            f->dataPtr = (void*)alt_py_ctx->dataPtr_pbyte;
            f->countPtr = alt_py_ctx->countPtr_pbyte;
            return 1;
        default:
            f->dssCtx = NULL;
            f->func = NULL;
            return 0;
    }
}

int AltDSS_Add_PyFunc(AltDSS_PyContextObject *self, FastDSSFuncInfo* finfo, PyObject *setObj, PyObject *fakeLib)
{
    PyObject **py_func = (PyObject**)(((char*)self) + finfo->attrOffset);
    PyObject *key = NULL;

    if (finfo->resType == fastdss_types_void)
    {
        switch (finfo->argType)
        {
            case fastdss_types_i32_i32:
            case fastdss_types_f64:
            case fastdss_types_i32:
            case fastdss_types_b16:
            case fastdss_types_str:
            case fastdss_types_void:
                *py_func = (PyObject*) PyObject_New(AltDSS_PyScalarSetterObject, &AltDSS_PyScalarSetterType);
                if ((*py_func) == NULL)
                {
                    goto ADD_FUNC_ERROR;
                }
                AltDSS_PyScalarSetter_cinit((AltDSS_PyScalarSetterObject*) *py_func, self, finfo);
                break;
            default:
                goto ADD_FUNC_ERROR;
        }        
    }
    else
    {
        switch (finfo->resType)
        {
            case fastdss_types_strs:
                *py_func = (PyObject*) PyObject_New(AltDSS_PyStrListGetterObject, &AltDSS_PyStrListGetterType);
                if ((*py_func) == NULL)
                {
                    goto ADD_FUNC_ERROR;
                }
                AltDSS_PyStrListGetter_cinit((AltDSS_PyStrListGetterObject*) *py_func, self, finfo);
                break;
            case fastdss_types_str:
                *py_func = (PyObject*) PyObject_New(AltDSS_PyStrGetterObject, &AltDSS_PyStrGetterType);
                if ((*py_func) == NULL)
                {
                    goto ADD_FUNC_ERROR;
                }
                AltDSS_PyStrGetter_cinit((AltDSS_PyStrGetterObject*) *py_func, self, finfo);
                break;
            case fastdss_types_f64:
            case fastdss_types_i32:
            case fastdss_types_b16:
                *py_func = (PyObject*) PyObject_New(AltDSS_PyScalarGetterObject, &AltDSS_PyScalarGetterType);
                if ((*py_func) == NULL)
                {
                    goto ADD_FUNC_ERROR;
                }
                AltDSS_PyScalarGetter_cinit((AltDSS_PyScalarGetterObject*) *py_func, self, finfo);
                break;
            case fastdss_types_gr_z128s:
            case fastdss_types_gr_z128:
            case fastdss_types_gr_f64s:
            case fastdss_types_gr_i32s:
            case fastdss_types_gr_i8s:
                *py_func = (PyObject*) PyObject_New(AltDSS_PyGRGetterObject, &AltDSS_PyGRGetterType);
                if ((*py_func) == NULL)
                {
                    goto ADD_FUNC_ERROR;
                }
                AltDSS_PyGRGetter_cinit((AltDSS_PyGRGetterObject*) *py_func, self, finfo);
                break;
            default:
                goto ADD_FUNC_ERROR;
        }
    }

    key = PyUnicode_FromString(finfo->fname);
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
    // printf("ERROR: function %s\n", fname);
    *py_func = NULL;
    Py_DECREF(key);
    return 0;
}
