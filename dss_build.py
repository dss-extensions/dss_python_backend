import numpy
from cffi import FFI
import sys, re, os
from dss_setup_common import PLATFORM_FOLDER
from setuptools import Extension

def process_header(src, extern_py=False, implement_py=False, prefix='', flags=None, fn='', remove=[]):
    '''Prepare the DSS C-API headers for parsing and building with CFFI'''
    
    src = src.replace('#endif // #ifdef HAS_ALTDSS_LOADER_FUNC', '')
    src = src.replace('#ifdef HAS_ALTDSS_LOADER_FUNC', '')

    if flags is not None:
        definitions = [x[2:] for x in flags] # remove -D
    else:
        definitions = None

    call_convention = '__stdcall ' if (sys.platform == 'win32') else ''

    for exp in remove:
        src = re.sub(exp, '', src, flags=re.MULTILINE)

    if definitions is not None:
        # Since we cannot easily use a C preprocessor here, some custom replacements
        if 'ALTDSS_USERMODEL' in definitions:
            src = src.replace('dss_long_bool', 'int32_t')
        else:
            src = src.replace('dss_long_bool', 'bool')

        candidate_definitions = ['ALTDSS_USERMODEL', 'OPENDSS_USERMODEL_V7', 'OPENDSS_USERMODEL_V10']

        cond = re.escape('#if defined(ALTDSS_USERMODEL) || defined(OPENDSS_USERMODEL_V7)')
        m = re.search(f'^{cond}\n(.*?)\n#else // {cond}\n(.*?)\n#endif // {cond}', src, flags=re.DOTALL|re.IGNORECASE|re.MULTILINE)
        assert m
        src = src.replace(m.group(0), 
            m.group(1) 
            if ('ALTDSS_USERMODEL' in definitions or 'OPENDSS_USERMODEL_V7' in definitions) else 
            m.group(2)
        )

        for candidate in candidate_definitions:
            cond = re.escape(f'#ifdef {candidate}')
            m = re.search(f'^{cond}\n(.*?)\n#else // {cond}\n(.*?)\n#endif // {cond}', src, flags=re.DOTALL|re.IGNORECASE|re.MULTILINE)
            if m:
                src = src.replace(m.group(0), 
                    m.group(1) 
                    if (candidate in definitions) else 
                    m.group(2)
                )

            m = re.search(f'^{cond}\n(.*?)\n#endif // {cond}', src, flags=re.DOTALL|re.IGNORECASE|re.MULTILINE)
            if m:
                src = src.replace(m.group(0), 
                    m.group(1) 
                    if (candidate in definitions) else 
                    ''
                )

    src = re.sub('^.*namespace .*$', '', src, flags=re.MULTILINE)
    if not implement_py:
        src = re.sub('^extern .*', '', src, flags=re.MULTILINE)
        src = re.sub('^.*extern .*$', '', src, flags=re.MULTILINE)
        src = re.sub('^#.*', '', src, flags=re.MULTILINE)
        src = re.sub('(DSS_CAPI_.*DLL)|(ALTDSS_.*_DLL)', '', src)
        
        # Remove functions for GR strings, deprecated
        non_gr_str_list = re.findall(r'^\s*void (\w+)\(const\s+void\*\s*ctx,\s*char\s*\*\*\*\s*\w+,\s*int32_t\s*\*\s*\w+', src, flags=re.MULTILINE)
        non_gr_str_list += re.findall(r'^\s*void (\w+)\(char\s*\*\*\*\s*\w+,\s*int32_t\s*\*\s*\w+', src, flags=re.MULTILINE)
        for non_gr_name in non_gr_str_list:
            src = re.sub(rf'^\s*void\s+({non_gr_name})_GR.*', '', src, count=1, flags=re.MULTILINE)

        src = re.sub(
            r'DSS_MODEL_CALLBACK\(([^,]+), ([^\)]+)\)', 
            r'\1 ({call_convention}*\2)'.format(call_convention=call_convention), 
            src
        )
    
    if extern_py:
        src = re.sub(
            r'DSS_MODEL_DLL\(([^\)]+)\) ', 
            r'extern "Python" \1 {prefix}'.format(prefix=prefix), 
            src
        )
        
    elif implement_py:
        # Extract the parameters from the definitions and implement a 
        # simple redirect to the Python-defined functions
        out_lines = []
        for line in src.split('\n'):
            if 'DSS_MODEL_DLL' not in line:
                out_lines.append(line)
                continue
        
            match = re.match(r'DSS_MODEL_DLL\((.*)\) (\w+)\((.*)\);', line)
            rtrn = 'return ' if match.group(1) != 'void' else ''
            name = match.group(2)
            if match.group(3) == 'void':
                params = []
            else:
                params = [
                    p.split(' ')[-1].strip('*') 
                    for p in match.group(3).split(',')
                ]
            
            out_lines.append(re.sub(
                r'DSS_MODEL_DLL\(([^\)]+)\) \w+\((.*)\);',
                r'''
static \1 {prefix}{name}(\2);
DSS_MODEL_DLL(\1) {name}(\2)
{{
    {rtrn}{prefix}{name}({params});
}}
'''.format(rtrn=rtrn, name=name, prefix=prefix, params=', '.join(params)), 
                line
            ))
            
        src = '\n'.join(out_lines)

    return src
    
extra = {}

# This ensures the shared libraries in the module directory can be
# loaded without changing LD_LIBRARY_PATH.
if sys.platform == 'linux':
    extra['extra_link_args'] = ["-Wl,-R,$ORIGIN/."]

ffi_builders = {}    

src_path = os.environ.get('SRC_DIR', '')
DSS_CAPI_PATH = os.environ.get('DSS_CAPI_PATH', os.path.join(src_path, '..', 'dss_capi'))

ffi_builder_dss = FFI()
ffi_builders['dss_loader'] = ffi_builder_dss

# main_header_fn = os.path.join(DSS_CAPI_PATH, 'include', 'altdss', 'capi', 'dss_ctx.h')
main_header_fn = os.path.join(DSS_CAPI_PATH, 'include', 'altdss', 'capi', 'capi.h')
common_header_fn = os.path.join(DSS_CAPI_PATH, 'include', 'altdss', 'capi', 'common.h')
enums_header_fn = os.path.join(DSS_CAPI_PATH, 'include', 'altdss', 'capi', 'enums.h')
# dss_capi_ctx_path = os.path.join(DSS_CAPI_PATH, 'include', 'altdss', 'capi', 'dss_ctx.h')
extra_headers = [enums_header_fn, ]

if common_header_fn:
    with open(common_header_fn, 'r') as f:
        # Remove the functions from the common header, only use the other defs
        cffi_header_dss = process_header(f.read(), fn=common_header_fn, remove=[r'^\s*ALTDSS_CAPI_DLL.*$', r'^\s*HMODULE.*$'])
else:
    cffi_header_dss = ''

with open(main_header_fn, 'r') as f:
    src = f.read().replace('ALTDSS_CAPI_DLL', '')
    cffi_header_dss += process_header(src, fn=main_header_fn, remove=[r'^\s*HMODULE.*$'])


for extra_fn in extra_headers:
    if os.path.exists(extra_fn):
        with open(extra_fn, 'r') as f:
            cffi_header_dss += process_header(f.read())

with open('cffi/dss_capi_custom.h', 'r') as f:
    extra_header_dss = f.read()
    
cffi_header_dss += extra_header_dss
extra_source_dss = ''
with open('cffi/dss_capi_custom.c', 'r') as f:
    extra_source_dss = '#include <altdss/capi/enums.h>\n'
    extra_source_dss += '#include <altdss/capi/common.h>\n'
    extra_source_dss += '#include <altdss/capi/capi.h>\n'
    extra_source_dss += f.read()

ffi_builder_dss.cdef(cffi_header_dss)

lib_dir = os.path.join(DSS_CAPI_PATH, 'lib/{}'.format(PLATFORM_FOLDER))
inc_dir = os.path.join(DSS_CAPI_PATH, 'include')

ffi_builder_dss.set_source(f"_altdss_capi_loader", extra_source_dss,
    libraries=['altdss_capi_loader'],
    define_macros = [('HAS_ALTDSS_LOADER_FUNC', 1)],
    library_dirs=[
        lib_dir
    ],
    include_dirs=[
        inc_dir,
        # os.path.join(DSS_CAPI_PATH, 'include/altdss'),
    ],
    source_extension='.c',
    **extra
)

# User-model modules/DLLs
# Currently we build a separate DLL for each kind of model,
# since some functions are different. Some could probably be 
# merged in a single DLL, but there's not much benefit.

with open(os.path.join(DSS_CAPI_PATH, 'include/dss_UserModels.h'), 'r') as f:
    raw_header_um = f.read()
    
user_models = [
    'GenUserModel',
    # 'PVSystemUserModel',
    # 'StoreDynaModel',
    # 'StoreUserModel',
    # 'CapUserControl',
]    

variant_options = {
    'AltDSS': ['-DALTDSS_USERMODEL'],
    'OpenDSS_v7': ['-DOPENDSS_USERMODEL_V7'],
    'OpenDSS_v8v9': [],
    'OpenDSS_v10': ['-DOPENDSS_USERMODEL_V10']
}

for user_model in user_models:
    with open(os.path.join(DSS_CAPI_PATH, 'include', 'dss_{}.h'.format(user_model)), 'r') as f:
        func_def = f.read()
        
    prefix = "py{}_".format(user_model)
    user_model_def = process_header(func_def, extern_py=True, prefix=prefix)
    user_model_src = process_header(func_def, implement_py=True, prefix=prefix)

    for variant, variant_flags in variant_options.items():
        cffi_header_um_variant = process_header(raw_header_um, flags=variant_flags)
        ffi_builder = FFI()
        ffi_builder.cdef(cffi_header_um_variant + user_model_def, packed=True)
        ffi_builder.set_source(f"_dss_{user_model}_{variant}", user_model_src,
            libraries=[],
            library_dirs=[],
            include_dirs=[inc_dir],
            source_extension='.c',
            extra_compile_args=variant_flags,
            #extra_link_args=['/DYNAMICBASE:NO', '/NXCOMPAT:NO']
        )
        ffi_builders[f'{user_model}-{variant}'] = ffi_builder
        
# Is there a better way to do this? Unfortunately setup(cffi_modules=...)
# needs a list of strings and cannot handle objects directly
ffi_builder_GenUserModel_altdss = ffi_builders['GenUserModel-AltDSS']
ffi_builder_GenUserModel_v7 = ffi_builders['GenUserModel-OpenDSS_v7']
ffi_builder_GenUserModel_v8v9 = ffi_builders['GenUserModel-OpenDSS_v8v9']
ffi_builder_GenUserModel_v10 = ffi_builders['GenUserModel-OpenDSS_v10']
#ffi_builder_PVSystemUserModel = ffi_builders['PVSystemUserModel']
#ffi_builder_StoreDynaModel = ffi_builders['StoreDynaModel']
#ffi_builder_StoreUserModel = ffi_builders['StoreUserModel']
#ffi_builder_CapUserControl = ffi_builders['CapUserControl']


_fast_dss_options = dict(
    py_limited_api=True,
    include_dirs=[numpy.get_include(), inc_dir],
    libraries=['altdss_capi_loader'],
    library_dirs=[lib_dir],
    **extra
    # extra_compile_args=['-g', '-O0'],
    # extra_link_args=['-g'],
)

fastdss_extension = Extension('_fastdss', ["src/_fastdss.c"], **_fast_dss_options)

if __name__ == "__main__":
    for version, builder in ffi_builders.items():
        print('-' * 40)
        print('Building', version)
        print('-' * 40)
        builder.compile(verbose=True)
        print()
