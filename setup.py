from distutils.core import setup, Extension


setup(
    name='houdini.py',
    version='0.1.0',
    description='A Python binding for Houdini.',
    author='Frank Smit',
    author_email='frank@61924.nl',
    url='http://python-houdini.61924.nl/',
    license='MIT',
    long_description=open('README.rst').read(),
    ext_modules=[Extension('houdini', [
        'src/houdini.py.c',
        'src/houdini/buffer.c',
        'src/houdini/houdini_js_e.c',
        'src/houdini/houdini_js_u.c',
        'src/houdini/houdini_uri_e.c',
        'src/houdini/houdini_uri_u.c',
        'src/houdini/houdini_html_e.c',
        'src/houdini/houdini_html_u.c'
    ])],
    classifiers = [
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: C',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3.2',
        'Topic :: Text Processing',
        'Topic :: Text Processing :: Filters',
        'Topic :: Utilities'
    ]
)
