[![Builds](https://github.com/dss-extensions/dss_python_backend/actions/workflows/builds.yml/badge.svg)](https://github.com/dss-extensions/dss_python_backenbd/actions/workflows/builds.yml)
[![PyPI](https://img.shields.io/pypi/v/dss_python_backend)](https://pypi.org/project/dss-python-backend/)
<img alt="Supports Linux" src="https://img.shields.io/badge/Linux-FCC624?logo=linux&logoColor=black"> <img alt="Supports macOS" src="https://img.shields.io/badge/macOS-000000?logo=apple&logoColor=white"> <img alt="Supports Microsoft Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white">

# DSS-Python: Backend

`dss_python_backend` provides low-level bindings for an implementation of EPRI's OpenDSS, using [CFFI](https://cffi.readthedocs.io/) and our [DSS C-API library and headers](https://github.com/dss-extensions/dss_capi/). It contains the native libraries (and DLLs) required by DSS-Python. This is considered an implementation detail.

**This is not intended for direct usage, [see DSS-Python](https://github.com/dss-extensions/DSS-Python/), [OpenDSSDirect.py](https://github.com/dss-extensions/OpenDSSDirect.py/), and [AltDSS-Python](https://github.com/dss-extensions/AltDSS-Python/) instead!**

After several years integrated into DSS-Python, this package was created in April 2023 to make the maintenance easier. See https://github.com/dss-extensions/dss_python/issues/51

The Python package includes:
- FastDSS modules for AltDSS/DSS C-API
- CFFI modules for AltDSS/DSS C-API
- CFFI modules for user-models (only the code for generator user-models is being compiled nowadays)
- AltDSS/DSS C-API related libraries (AltDSS Engine, Oddie, Loader, etc.), DLLs, and headers

This module contains source-code licensed under BSD3 and LGPL3. See each file for SPDX comments.

Although this repository does not contain code from OpenDSS, the license is listed in `OPENDSS_LICENSE` for reference. The final packages do include software derived from OpenDSS code and other libraries, such as KLUSolveX and KLU (from SuiteSparse), both licensed under the LGPL. Since the files listed in this repository contain multiple licenses, SPDX identifiers are now included in the file headers.

*Note: this package might be renamed in the future to reflect the new developments.*