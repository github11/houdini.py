cimport houdini
from houdini cimport const_char
from libc.string cimport strndup

__version__ = '0.1.0'


cpdef char* escape_html(unsigned char *text, int secure=0):
    cdef char *result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_escape_html0(ob, text, len(text), secure)

    result = strndup(<const_char *> ob.data, ob.size)
    houdini.bufrelease(ob)

    return result


cpdef char* unescape_html(unsigned char *text):
    cdef char *result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_unescape_html(ob, text, len(text))

    result = strndup(<const_char *> ob.data, ob.size)
    houdini.bufrelease(ob)

    return result


cpdef char* escape_uri(unsigned char *text):
    cdef char *result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_escape_uri(ob, text, len(text))

    result = strndup(<const_char *> ob.data, ob.size)
    houdini.bufrelease(ob)

    return result


cpdef char* escape_url(unsigned char *text):
    cdef char *result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_escape_url(ob, text, len(text))

    result = strndup(<const_char *> ob.data, ob.size)
    houdini.bufrelease(ob)

    return result


cpdef char* unescape_uri(unsigned char *text):
    cdef char *result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_unescape_uri(ob, text, len(text))

    result = strndup(<const_char *> ob.data, ob.size)
    houdini.bufrelease(ob)

    return result


cpdef char* unescape_url(unsigned char *text):
    cdef char *result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_unescape_url(ob, text, len(text))

    result = strndup(<const_char *> ob.data, ob.size)
    houdini.bufrelease(ob)

    return result


cpdef char* escape_js(unsigned char *text):
    cdef char *result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_escape_js(ob, text, len(text))

    result = strndup(<const_char *> ob.data, ob.size)
    houdini.bufrelease(ob)

    return result


cpdef char* unescape_js(unsigned char *text):
    cdef char *result
    cdef houdini.buf *ob = houdini.bufnew(128)

    houdini.houdini_unescape_js(ob, text, len(text))

    result = strndup(<const_char *> ob.data, ob.size)
    houdini.bufrelease(ob)

    return result
