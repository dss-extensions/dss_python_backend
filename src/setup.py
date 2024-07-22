from distutils.core import setup, Extension
import numpy

def main():
    setup(name="_fast",
          version="0.0.1",
          description="A couple of fast functions for DSS-Extensions/AltDSS packages",
          author="Paulo Meira",
          author_email="pmeira@ieee.org",
          ext_modules=[Extension("_fast", ["_fast.c"], include_dirs=[numpy.get_include()])])

if __name__ == "__main__":
    main()
