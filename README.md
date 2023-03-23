# posicxx
## README

CXX-style wrappers around POSIX functionality for CXX11 onwards

### Summarising

At the very least, this library provides wrapped functionality, which consist of one-off calls to the POSIX API found in libc functionality enveloped in namespace `posicxx` and guarded with error-handling in the form of CXX exceptions.

For many operations, there will also exist intuitive interfaces to ensure proper resource management (think RAII).

Instead of including `*.h`, use extension `.hh` (i.e. `*.hh`) to include the wrapped code.

If you're doing systems programming in C++ and don't want to write 3+ lines for every simple system call being made, then this is the library for you. Whether you choose the basic wrappers or the more black-box functionality, it's better than the alternative with a minimal performance cost.

Status of wrapper implementations (if unspecified, assume only core wrapper exists / no interface):
* aio.hh
* arpa/
  * inet.hh
* assert.hh (done)
* complex.hh
* contents
* cpio.hh
* ctype.hh
* dirent.hh
* dlfcn.hh
* errno.hh
* fcntl.hh
* fenv.hh
* float.hh
* fmtmsg.hh
* fnmatch.hh
* ftw.hh
* glob.hh
* grp.hh
* iconv.hh
* inttypes.hh
* iso646.hh
* langinfo.hh
* libgen.hh
* limits.hh
* locale.hh
* math.hh
* monetary.hh
* mqueue.hh
* ndbm.hh
* net/
  * if.hh
* netdb.hh
* netinet/
  * in.hh
  * tcp.hh
* nl_types.hh
* poll.hh
* pthread.hh
* pwd.hh
* regex.hh
* sched.hh
* search.hh
* semaphore.hh
  * Core Wrapper (done)
  * Interface
* setjmp.hh
* signal.hh
* spawn.hh
* stdarg.hh
* stdbool.hh
* stddef.hh
* stdint.hh
* stdio.hh
* stdlib.hh
* string.hh
* strings.hh
* stropts.hh
* sys/
  * ipc.hh
  * mman.hh
  * msg.hh
  * resource.hh
  * select.hh
  * em.hh
  * shm.hh
  * socket.hh
  * stat.hh
  * stavfs.hh
  * time.hh
  * timeb.hh
  * times.hh
  * types.hh
  * uio.hh
  * un.hh
  * utsname.hh
  * wait.hh
* syslog.hh
* tar.hh
* termios.hh
* tgmath.hh
* time.hh
* trace.hh
* ucontext.hh
* ulimit.hh
* unistd.hh
* utime.hh
* utmpx.hh
* wchar.hh
* wctype.hh
* wordexp.hh

### Building

Building requires use of GNU `make` utility, with instructions listed in the `Makefile` file.
Number of commands available:
* `make`/`make all` - builds library
* `make clean` - deletes all compiled output

Documentation uses the `doxygen` tool.
Run `doxygen .doxygen/config.txt` to generate up-to-date documentation.

### Using

You will need to include the relevant headers as you would for the libc alternatives

```
For example:

> `#include <semaphore.h>`

is now

> `#include <semaphore.hh>`

```

This *includes* files which merely contain macro-value definitions (for the sake of consistency)

Note that the CXX header will also include the libc equivalent also without adulterations.

You will need to link your binaries with `posicxx.a` at compile-time

See `docs/` for documentation.

***

See LICENSE for terms of usage.

