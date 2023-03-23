# posicxx
## README

CXX-style wrappers around POSIX functionality for CXX11 onwards

### Summarising Code

At the very least, the wrapped functionality are one-off calls to the POSIX API found in libc functionality, enforcing namespaces, return-code checking and throwing informative errors if an invalid return is detected.

However, for many operations, there will exist intuitive functionality, mainly functionality following the RAII idiom, to ensure resources / memory management, such as the auto-deallocation of resources should they go out-of-scope.

If you're doing systems programming in C++ and don't want to write 3+ lines for every simple system call being made, then this is the library for you. Whether you choose the basic wrappers or more advanced functionality, it's better than the alternative with a minimal performance cost.

### Building

Building requires use of GNU `make` utility, with instructions listed in the `Makefile` file.
Number of commands available:
* `make`/`make all` - builds library
* `make clean` - deletes all compiled output

Documentation uses the `doxygen` tool.
Run `doxygen .doxygen/config.txt` to generate up-to-date documentation.

### Using

You will need to include the relevant headers as you would for the libc alternatives

>>> `#include <semaphore.h>`
>>> is now
>>> `#include <semaphore.hh>`

You will need to link your binaries with `posicxx.a` at compile-time

See `docs/` for documentation.

***

See LICENSE for terms of usage.

