from distutils.core import setup, Extension
import numpy

def main():
    options_dict = dict(
        include_dirs=[numpy.get_include()],
        libraries=['dss_capi'],
        library_dirs=['../../dss_capi/lib/linux_x64'],
        extra_link_args=["-Wl,-R,$ORIGIN/."],
    )

    setup(name="_fast",
          version="0.0.1",
          description="A couple of fast functions for DSS-Extensions/AltDSS packages",
          author="Paulo Meira",
          author_email="pmeira@ieee.org",
          ext_modules=[Extension("_fast", ["_fast.c"], **options_dict)])

if __name__ == "__main__":
    main()
