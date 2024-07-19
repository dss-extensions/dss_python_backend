from distutils.core import setup, Extension

def main():
    setup(name="_faststr",
          version="0.0.1",
          description="A couple of fast functions for DSS-Extensions/AltDSS packages",
          author="Paulo Meira",
          author_email="pmeira@ieee.org",
          ext_modules=[Extension("_faststr", ["_faststr.c"])])

if __name__ == "__main__":
    main()
