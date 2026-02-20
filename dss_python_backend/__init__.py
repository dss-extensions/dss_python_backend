'''dss_python_backend (or "DSS-Python: Backend") contains the native libraries for the DSS Engine from DSS-Extensions.org.
The CFFI module is used to bind the native libs, by processing the DSS C-API headers.

Previous to DSS-Python version 0.14.0, this backend was included in the same module.

For better maintenance and evolution of the Python-only code, the module was split in two. 
'''

import os, sys
from . import _altdss_capi_loader
from ._altdss_capi_loader import ffi, lib as loader_lib
from pathlib import Path

altdss_lib_parent_path = Path(_altdss_capi_loader.__file__).absolute().parent

if sys.platform == 'win32':
    DLL_SUFFIX = '.dll'
    DLL_PREFIX = ''
elif sys.platform in ('linux', 'linux2'):
    DLL_SUFFIX = '.so'
    DLL_PREFIX = 'lib'
elif sys.platform == 'darwin':
    DLL_SUFFIX = '.dylib'
    DLL_PREFIX = 'lib'
else:
    raise RuntimeError("Unsupported platform!")

if os.environ.get('DSS_EXTENSIONS_DEBUG', '') != '1':
    altdss_lib_path = altdss_lib_parent_path.joinpath(f'{DLL_PREFIX}altdss_capi{DLL_SUFFIX}')
else:
    import warnings
    warnings.warn('Environment variable DSS_EXTENSIONS_DEBUG=1 is set: loading the debug version of the DSS C-API library')
    altdss_lib_path = altdss_lib_parent_path.joinpath(f'{DLL_PREFIX}altdss_capid{DLL_SUFFIX}')

if not altdss_lib_path.exists():
    raise RuntimeError('AltDSS library not found!')

# Basic initialization -- load the library and prepare the structures
lib = _altdss_capi_loader.ffi.new('AltDSSCAPI*')

_init_result = loader_lib.AltDSSCAPILibInit(
    str(altdss_lib_path).encode(),
    ffi.NULL,
    b"AltDSSCAPIInit",
    lib,
    ffi.sizeof(lib[0]), 
    0,
    0,
    ffi.NULL
)

if _init_result != 1:
    raise RuntimeError(f'AltDSS library found but could not be loaded (code {_init_result})!')

# For AltDSS, ensure this is called at least once. This was moved from 
# CffiApiUtil so we call it as soon as the DLL/so is loaded.
lib.DSS_Start(ffi.NULL, 0)

__version__ = '0.15.0b3'
__all__ = ['ffi', 'lib', 'loader_lib']
