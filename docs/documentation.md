## Introduction

Houdini.py is a Python binding for [Houdini][0] that provides (un)escaping
functions for HTML, URLs/URIs and Javascript. It has been tested on Python 2.7
and 3.2.

 [0]: https://github.com/tanoku/houdini


## Installation

Download Houdini.py from [Github][1] and run the following command. Keep in
mind that Houdini.py has only been tested with Python 2.7 and 3.2.

    python setup.py install

Or from PyPi:

    pip install houdini.py

And you're done.


 [1]: https://github.com/FSX/houdini.py


## Usage

Example:

~~~~ {.python}
import houdini as h

print h.escape_html('<b>test</b>')
print h.escape_html('&lt;b&gt;test&lt;/b&gt;')
~~~~


## API

All of the following functions and constants are from the `houdini` module.

 * `escape_html`
 * `unescape_html`
 * `escape_uri`
 * `unescape_uri`
 * `escape_url`
 * `unescape_url`
 * `escape_js`
 * `unescape_js`

All methods, except `escape_html`, accept one argument: the text that needs to
be escape or unescaped. `escape_html` accepts an optional second argument:
`secure`. When `secure` is `1` forward slashes will also be escaped. It's `0`
by default.


## Changelog

### 0.1.0 (2011-09-12)

 * Initial release.


## License

Copyright (C) 2011 by Frank Smit <frank@61924.nl>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
