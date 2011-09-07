cimport houdini

__version__ = '0.1.0'


cpdef bytes escape_html(unsigned char *text, int secure=0):
    cdef bytes py_result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_escape_html(ob, text, len(text), secure)

    py_result = ob.data
    py_result = py_result[:ob.size]
    houdini.bufrelease(ob)

    return py_result


cpdef bytes unescape_html(unsigned char *text):
    cdef bytes py_result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_unescape_html(ob, text, len(text))

    py_result = ob.data
    py_result = py_result[:ob.size]
    houdini.bufrelease(ob)

    return py_result


cpdef bytes escape_uri(unsigned char *text):
    cdef bytes py_result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_escape_uri(ob, text, len(text))

    py_result = ob.data
    py_result = py_result[:ob.size]
    houdini.bufrelease(ob)

    return py_result


cpdef bytes escape_url(unsigned char *text):
    cdef bytes py_result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_escape_url(ob, text, len(text))

    py_result = ob.data
    py_result = py_result[:ob.size]
    houdini.bufrelease(ob)

    return py_result


cpdef bytes unescape_uri(unsigned char *text):
    cdef bytes py_result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_unescape_uri(ob, text, len(text))

    py_result = ob.data
    py_result = py_result[:ob.size]
    houdini.bufrelease(ob)

    return py_result


cpdef bytes unescape_url(unsigned char *text):
    cdef bytes py_result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_unescape_url(ob, text, len(text))

    py_result = ob.data
    py_result = py_result[:ob.size]
    houdini.bufrelease(ob)

    return py_result
