#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "houdini/buffer.h"
#include "houdini/houdini.h"


static PyObject *
py_escape_html(PyObject *self, PyObject *args)
{
    PyObject *py_result;
    unsigned char *text;
    size_t text_size;
    int secure = 0;

    if (!PyArg_ParseTuple(args, "s#|i", &text, &text_size, &secure)) {
        return NULL;
    }

    /* Escape text */
    struct buf *ob = bufnew(128);
    houdini_escape_html0(ob, text, text_size, secure);

    /* Make a Python string */
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);

    /* Cleanup */
    bufrelease(ob);
    return py_result;
}


static PyObject *
py_unescape_html(PyObject *self, PyObject *args)
{
    PyObject *py_result;
    unsigned char *text;
    size_t text_size;

    if (!PyArg_ParseTuple(args, "s#", &text, &text_size)) {
        return NULL;
    }

    /* Escape text */
    struct buf *ob = bufnew(128);
    houdini_unescape_html(ob, text, text_size);

    /* Make a Python string */
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);

    /* Cleanup */
    bufrelease(ob);
    return py_result;
}


static PyObject *
py_escape_uri(PyObject *self, PyObject *args)
{
    PyObject *py_result;
    unsigned char *text;
    size_t text_size;

    if (!PyArg_ParseTuple(args, "s#", &text, &text_size)) {
        return NULL;
    }

    /* Escape text */
    struct buf *ob = bufnew(128);
    houdini_escape_uri(ob, text, text_size);

    /* Make a Python string */
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);

    /* Cleanup */
    bufrelease(ob);
    return py_result;
}


static PyObject *
py_escape_url(PyObject *self, PyObject *args)
{
    PyObject *py_result;
    unsigned char *text;
    size_t text_size;

    if (!PyArg_ParseTuple(args, "s#", &text, &text_size)) {
        return NULL;
    }

    /* Escape text */
    struct buf *ob = bufnew(128);
    houdini_escape_url(ob, text, text_size);

    /* Make a Python string */
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);

    /* Cleanup */
    bufrelease(ob);
    return py_result;
}


static PyObject *
py_unescape_uri(PyObject *self, PyObject *args)
{
    PyObject *py_result;
    unsigned char *text;
    size_t text_size;

    if (!PyArg_ParseTuple(args, "s#", &text, &text_size)) {
        return NULL;
    }

    /* Escape text */
    struct buf *ob = bufnew(128);
    houdini_unescape_uri(ob, text, text_size);

    /* Make a Python string */
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);

    /* Cleanup */
    bufrelease(ob);
    return py_result;
}


static PyObject *
py_unescape_url(PyObject *self, PyObject *args)
{
    PyObject *py_result;
    unsigned char *text;
    size_t text_size;

    if (!PyArg_ParseTuple(args, "s#", &text, &text_size)) {
        return NULL;
    }

    /* Escape text */
    struct buf *ob = bufnew(128);
    houdini_unescape_url(ob, text, text_size);

    /* Make a Python string */
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);

    /* Cleanup */
    bufrelease(ob);
    return py_result;
}


static PyObject *
py_escape_js(PyObject *self, PyObject *args)
{
    PyObject *py_result;
    unsigned char *text;
    size_t text_size;

    if (!PyArg_ParseTuple(args, "s#", &text, &text_size)) {
        return NULL;
    }

    /* Escape text */
    struct buf *ob = bufnew(128);
    houdini_escape_js(ob, text, text_size);

    /* Make a Python string */
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);

    /* Cleanup */
    bufrelease(ob);
    return py_result;
}


static PyObject *
py_unescape_js(PyObject *self, PyObject *args)
{
    PyObject *py_result;
    unsigned char *text;
    size_t text_size;

    if (!PyArg_ParseTuple(args, "s#", &text, &text_size)) {
        return NULL;
    }

    /* Escape text */
    struct buf *ob = bufnew(128);
    houdini_unescape_js(ob, text, text_size);

    /* Make a Python string */
    py_result = Py_BuildValue("s#", ob->data, (int)ob->size);

    /* Cleanup */
    bufrelease(ob);
    return py_result;
}


static PyMethodDef houdini_methods[] = {
    {"escape_html", py_escape_html, METH_VARARGS, "Escape HTML"},
    {"unescape_html", py_unescape_html, METH_VARARGS, "Unescape HTML"},
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
