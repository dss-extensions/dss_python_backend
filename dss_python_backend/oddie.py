'''
This file provides access to the Oddie library.
Note that it does not initialize the OpenDSS or OpenDSS-C libraries, that is a 
second step. The same Oddie instance can be used to load multiple engine libraries.
'''
import os
from . import _altdss_capi_loader
from ._altdss_capi_loader import ffi, lib as loader_lib
from pathlib import Path

altdss_lib_parent_path = Path(_altdss_capi_loader.__file__).absolute().parent

if os.environ.get('DSS_EXTENSIONS_DEBUG', '') != '1':
    oddie_lib_path = altdss_lib_parent_path.joinpath('libaltdss_oddie_capi.so')
else:
    import warnings
    warnings.warn('Environment variable DSS_EXTENSIONS_DEBUG=1 is set: loading the debug version of the AltDSS Oddie library')
    oddie_lib_path = altdss_lib_parent_path.joinpath('libaltdss_oddie_capid.so')

if not oddie_lib_path.exists():
    print(oddie_lib_path)
    raise RuntimeError('Oddie library not found!')

# Basic initialization -- load the library and prepare the structures
lib = _altdss_capi_loader.ffi.new('AltDSSCAPI*')

_init_result = loader_lib.AltDSSCAPILibInit(
    str(oddie_lib_path).encode(),
    ffi.NULL,
    b"AltDSSOddieCAPIInit",
    lib,
    ffi.sizeof(lib[0]), 
    0,
    0,
    ffi.NULL
)

if _init_result != 1:
    raise RuntimeError(f'Oddie library found but could not be loaded (code {_init_result})!')

# Compared to the main "lib" in __init__.py, we will not call DSS_Start yet
# since the actual engine is not loaded.
