from distutils.core import setup, Extension
from Cython.Distutils import build_ext


setup(
    name='houdini',
    version='0.1.0',
    description='A Python binding for Houdini.',
    author='Frank Smit',
    author_email='frank@61924.nl',
    license='MIT',
    long_description=open('README.txt').read(),
    cmdclass = {'build_ext': build_ext},
    ext_modules=[Extension('houdini', [
        'src/houdini.py.pyx',
        'src/houdini/buffer.c',
        'src/houdini/houdini_uri.c',
        'src/houdini/houdini_html.c'
    ])],
    classifiers = [
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Cython',
        'Topic :: Text Processing',
        'Topic :: Text Processing :: Filters',
        'Topic :: Utilities'
    ]
)
