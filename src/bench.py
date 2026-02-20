from _faststr import addr_to_str, addr_to_strs, AltDSSStrFunc, AltDSSStrListFunc
from dss import dss, api_util, DSSException

dss('redirect ../../electricdss-tst/Version8/Distrib/IEEETestCases/8500-Node/Master.dss')

lib = api_util.lib
lib_unpatched = api_util.lib_unpatched
ffi = api_util.ffi
circ = dss.ActiveCircuit
bus = circ.ActiveBus

def arrayversion1():
    ptr = ffi.new('char***')
    cnt = ffi.new('int32_t[4]')
    lib.Circuit_Get_AllBusNames(ptr, cnt)
    return addr_to_strs(int(ffi.cast('uintptr_t', ptr[0])), int(cnt[0]))
    
arrayversion0 = lambda: circ.AllBusNames

arrayversion2 = AltDSSStrListFunc(
    int(ffi.cast('uintptr_t', api_util.ctx)), # ctx
    int(ffi.cast('uintptr_t', api_util._errorPtr)), # errorPtr
    int(ffi.cast('uintptr_t', ffi.addressof(lib_unpatched, 'ctx_Circuit_Get_AllBusNames'))), # func
    int(ffi.cast('uintptr_t', ffi.addressof(lib_unpatched, 'ctx_Error_Get_Description'))), # errorDescFunc
    int(ffi.cast('uintptr_t', ffi.addressof(lib_unpatched, 'DSS_Dispose_PPAnsiChar'))), # disposeFunc
    DSSException, # DSSExceptionType
)



# &dssCtx, &errorPtr, &func, &errorDescFunc, &f->DSSExceptionType
version2 = AltDSSStrFunc(
    int(ffi.cast('uintptr_t', api_util.ctx)), # ctx
    int(ffi.cast('uintptr_t', api_util._errorPtr)), # errorPtr
    int(ffi.cast('uintptr_t', ffi.addressof(lib_unpatched, 'ctx_Bus_Get_Name'))), # func
    int(ffi.cast('uintptr_t', ffi.addressof(lib_unpatched, 'ctx_Error_Get_Description'))), # errorDescFunc
    DSSException, # DSSExceptionType
)

def version1():
    return addr_to_str(int(ffi.cast('uintptr_t', lib.Bus_Get_Name())))
    # v0 = lib.DSS_Get_Version()
    # v = int(ffi.cast('uintptr_t', v0))
    # try:
    #     return addr_to_str(v)
    # except:
    #     print(hex(int(v)))
    #     print(v0)
    #     raise


version0 = lambda: bus.Name


from timeit import timeit

print('Single element')
t0 = timeit(version0)
t1 = timeit(version1)
t2 = timeit(version2)
print(t0)
print(t1)
print(t2)
print(100 * (t1 / t0))
print(100 * (t2 / t0))

print()
print('Arrays')
t0 = timeit(arrayversion0, number=1000)
t1 = timeit(arrayversion1, number=1000)
t2 = timeit(arrayversion2, number=1000)

print(t0)
print(t1)
print(t2)
print(100 * (t1 / t0))
print(100 * (t2 / t0))

print(version2())
res = arrayversion2()
print(res[:10])
print(res[-10:])