'''dss_python_backend (or "DSS-Python: Backend") contains the native libraries for the DSS Engine from DSS-Extensions.org.
The CFFI module is used to bind the native libs, by processing the DSS C-API headers.

Previous to DSS-Python version 0.14.0, this backend was included in the same module.

For better maintenance and evolution of the Python-only code, the module was split in two. 
'''

import os

if os.environ.get('DSS_EXTENSIONS_DEBUG', '') != '1':
    from ._dss_capi import ffi, lib
else:
    import warnings
    warnings.warn('Environment variable DSS_EXTENSIONS_DEBUG=1 is set: loading the debug version of the DSS C-API library')
    from ._dss_capid import ffi, lib

# Ensure this is called at least once. This was moved from 
# CffiApiUtil so we call it as soon as the DLL/so is loaded.
lib.DSS_Start(0)

__version__ = '0.14.1'
__all__ = ['ffi', 'lib']
