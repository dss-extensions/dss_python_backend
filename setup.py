from setuptools import setup
import re, shutil, os, io, sys, glob

sys.path.insert(0, os.path.dirname(__file__))

from dss_setup_common import PLATFORM_FOLDER, DLL_SUFFIX
import dss_build

SKIP_COPY = os.environ.get('DSS_PYTHON_BACKEND_SKIP_COPY', '0') == '1'

# Copy README.md contents
with io.open('README.md', encoding='utf8') as readme_md:
    long_description = readme_md.read()

# Handle the version string
# 1. Try env var DSS_PYTHON_BACKEND_VERSION
# 2. Try GITHUB_REF for a Git tag
# 3. Otherwise, just use the hardcoded version

package_version = os.environ.get('DSS_PYTHON_BACKEND_VERSION')
github_ref = os.environ.get('GITHUB_REF')
if package_version is None and github_ref is not None:
    package_version = github_ref[len("refs/tags/"):]

if package_version is not None:
    if re.match(r'^\d+\.\d+\.\d+((-\d+){0,1}|((a|b|(rc))\d*)|(\.dev\d+)){0,1}$', package_version) is None:        
        package_version = None

if package_version is None:
    # Extract version from the source files
    with open('dss_python_backend/__init__.py', 'r') as f:
        match = re.search("__version__ = '(.*?)'", f.read())
        package_version = match.group(1)
else:
    with open('dss_python_backend/__init__.py', 'r') as f:
        init_py_orig = f.read()

    init_py = re.sub("__version__ = '(.*?)'", f"__version__ = '{package_version}'", init_py_orig)
    if init_py_orig != init_py:
        with open('dss_python_backend/__init__.py', 'w') as f:
            f.write(init_py)

if os.environ.get('DSS_PYTHON_BACKEND_PREPARE_BOA') == '1':
    with open('conda/meta.yaml', 'r') as fin, open('conda/recipe.yaml', 'w') as fout:
        fout.write(fin.read().replace('{{ load_setup_py_data().version }}', package_version))

    exit()

# Copy all the DLLs from DSS C-API
src_path = os.environ.get('SRC_DIR', '')
DSS_CAPI_PATH = os.environ.get('DSS_CAPI_PATH', os.path.join(src_path, '..', 'dss_capi'))
base_dll_path_in = os.path.join(DSS_CAPI_PATH, 'lib', PLATFORM_FOLDER)
dll_path_out = os.path.abspath(os.path.join(src_path, 'dss_python_backend'))
include_path_out = os.path.join(dll_path_out, 'include')

if not SKIP_COPY:
    for fn in glob.glob(os.path.join(base_dll_path_in, '*{}'.format(DLL_SUFFIX))):
        shutil.copy(fn, dll_path_out)

# Copy libs (easier to build custom extensions with a default DSS Python installation)
for pattern in ('*.lib', '*.a', '*.pdb'):
    for fn in glob.glob(os.path.join(base_dll_path_in, pattern)):
        shutil.copy(fn, dll_path_out)

# Copy headers
if os.path.exists(include_path_out):
    shutil.rmtree(include_path_out)

shutil.copytree(os.path.join(DSS_CAPI_PATH, 'include'), include_path_out)

# Filter files to include in the Python package
extra_files = (
    glob.glob(os.path.join(include_path_out, '**', '*')) + 
    glob.glob(os.path.join(include_path_out, '*')) + 
    glob.glob(os.path.join(dll_path_out, '*.lib')) + 
    glob.glob(os.path.join(dll_path_out, '*.a'))
)    

extra_args = dict(package_data={
    'dss_python_backend': ['*{}'.format(DLL_SUFFIX)] + extra_files
})


setup(
    version=package_version,
    packages=['dss_python_backend', 'dss_python_backend.include'],
    setup_requires=["cffi>=2.0.0"],
    cffi_modules= [
        "dss_build.py:ffi_builder_dss",
        'dss_build.py:ffi_builder_GenUserModel_altdss', 
        'dss_build.py:ffi_builder_GenUserModel_v7', 
        'dss_build.py:ffi_builder_GenUserModel_v8v9', 
        'dss_build.py:ffi_builder_GenUserModel_v10', 
        #'dss_build.py:ffi_builder_PVSystemUserModel', 
        #'dss_build.py:ffi_builder_StoreDynaModel', 
        #'dss_build.py:ffi_builder_StoreUserModel', 
        #'dss_build.py:ffi_builder_CapUserControl'
    ],
    ext_modules=[dss_build.fastdss_extension],
    ext_package="dss_python_backend",
    # tests_require=["pytest"],
    zip_safe=False,
    **extra_args
)

