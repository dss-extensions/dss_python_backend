mkdir -p artifacts
cd dss_python_backend
$PYTHON -m pip install --upgrade pip setuptools packaging trove-classifiers cffi wheel numpy==2
$PYTHON setup.py --quiet bdist_wheel --py-limited-api cp37 --dist-dir=$ARTIFACTS_FOLDER
