#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "houdini/buffer.h"
#include "houdini/houdini.h"


#define PRE_ESCAPE \
    PyObject *py_result;\
    unsigned char *text;\
    size_t text_size;\
    if (!PyArg_ParseTuple(args, "s#", &text, &text_size))\
        return NULL;\
    struct buf *ob = bufnew(128);


#define POST_ESCAPE \
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);\
    bufrelease(ob);\
    return py_result;


static PyObject *
py_escape_html(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_escape_html0(ob, text, text_size, 0);
    POST_ESCAPE;
}


static PyObject *
py_unescape_html(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_unescape_html(ob, text, text_size);
    POST_ESCAPE;
}


static PyObject *
py_escape_href(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_escape_href(ob, text, text_size);
    POST_ESCAPE;
}


static PyObject *
py_escape_xml(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_escape_xml(ob, text, text_size);
    POST_ESCAPE;
}


static PyObject *
py_escape_uri(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_escape_uri(ob, text, text_size);
    POST_ESCAPE;
}


static PyObject *
py_escape_url(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_escape_url(ob, text, text_size);
    POST_ESCAPE;
}


static PyObject *
py_unescape_uri(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_unescape_uri(ob, text, text_size);
    POST_ESCAPE;
}


static PyObject *
py_unescape_url(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_unescape_url(ob, text, text_size);
    POST_ESCAPE;
}


static PyObject *
py_escape_js(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_escape_js(ob, text, text_size);
    POST_ESCAPE;
}


static PyObject *
py_unescape_js(PyObject *self, PyObject *args)
{
    PRE_ESCAPE;
    houdini_unescape_js(ob, text, text_size);
    POST_ESCAPE;
}


static PyMethodDef houdini_methods[] = {
    {"escape_html", py_escape_html, METH_VARARGS, "Escape HTML"},
    {"unescape_html", py_unescape_html, METH_VARARGS, "Unescape HTML"},
    {"escape_href", py_escape_href, METH_VARARGS, "Escape HREF"},
    {"escape_xml", py_escape_xml, METH_VARARGS, "Escape XML"},
    {"escape_uri", py_escape_uri, METH_VARARGS, "Escape URI"},
    {"escape_url", py_escape_url, METH_VARARGS, "Escape URL"},
    {"unescape_uri", py_unescape_uri, METH_VARARGS, "Unescape URI"},
    {"unescape_url", py_unescape_url, METH_VARARGS, "Unescape URL"},
    {"escape_js", py_escape_js, METH_VARARGS, "Escape JavaScript"},
    {"unescape_js", py_unescape_js, METH_VARARGS, "Unescape JavaScript"},
    {NULL, NULL, 0, NULL} /* Sentinel */
};


#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "houdini",
    NULL,
    -1,
    houdini_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyObject *
PyInit_houdini(void)
{
    PyObject *module = PyModule_Create(&moduledef);
    return module;
}
#else
PyMODINIT_FUNC
inithoudini(void)
{
    PyObject *module = Py_InitModule("houdini", houdini_methods);
}
#endif
