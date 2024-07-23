from distutils.core import setup, Extension
import numpy

def main():
    options_oddie = dict(
        include_dirs=[numpy.get_include()],
        libraries=['altdss_oddie_capi'],
        #library_dirs=['../../dss_capi/lib/linux_x64'],
        library_dirs=['../../dss_capi/lib/win_x64'],
        #extra_link_args=["-Wl,-R,$ORIGIN/."],
        # extra_compile_args=['/Zi', f'/DALTDSS_FAST_MODNAME="_fastdss_oddie"', f'/DALTDSS_FAST_MODINIT=PyInit__fastdss_oddie', '/DALTDSS_ODDIE'],
        # extra_link_args=['/DEBUG']
        extra_compile_args=[f'/DALTDSS_FAST_MODNAME="_fastdss_oddie"', f'/DALTDSS_FAST_MODINIT=PyInit__fastdss_oddie', '/DALTDSS_ODDIE'],
    )

    options_alt = dict(
        include_dirs=[numpy.get_include()],
        libraries=['dss_capi'],
        #library_dirs=['../../dss_capi/lib/linux_x64'],
        library_dirs=['../../dss_capi/lib/win_x64'],
        #extra_link_args=["-Wl,-R,$ORIGIN/."],
        # extra_compile_args=['/Od', '/Zi', f'/DALTDSS_FAST_MODNAME="_fastdss"', f'/DALTDSS_FAST_MODINIT=PyInit__fastdss'],
        # extra_link_args=['/DEBUG']
        extra_compile_args=[f'/DALTDSS_FAST_MODNAME="_fastdss"', f'/DALTDSS_FAST_MODINIT=PyInit__fastdss'],
    )

    setup(name='dss_python_backend',
          version="0.0.1",
          description="A couple of fast functions for DSS-Extensions/AltDSS packages",
          author="Paulo Meira",
          author_email="pmeira@ieee.org",
          ext_modules=[
            Extension('_fastdss_oddie', ["_fast.c"], **options_oddie),
            Extension('_fastdss', ["_fast.c"], **options_alt)
          ])

if __name__ == "__main__":
    main()
