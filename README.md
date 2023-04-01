# posicxx
## README

CXX-style wrappers around POSIX functionality for CXX11 onwards

### Summarising

At the very least, this library provides wrapped functionality, which consist of one-off calls to the POSIX API found in libc functionality enveloped in namespace `posicxx` and guarded with error-handling in the form of CXX exceptions with detailed errors.

For select groups of functionality, there will also exist resource-managed containers (think RAII) & overloads for procedure to seamlessly utilise said containers in place of raw resources.

Instead of including `*.h`, use extension `.hh` (i.e. `*.hh`) to include the wrapped code.

If you're doing systems programming in C++ and don't want to write 3 >= lines for every simple system call being made, then this is the library for you. Whether you choose the basic wrappers or the managerial functionality, it's better than the alternative with a minimal performance cost.

Status of wrapper implementations (if unspecified, assume only core wrapper exists / no additional interface(s)):
* aio.hh
* arpa/
  * inet.hh
* complex.hh
* ctype.hh
* dirent.hh
* dlfcn.hh
* ~~errno.hh~~ (*not done*, use error.hh instead)
* error.hh
  * Custom implementation to throw errno-based exceptions (done)
* fcntl.hh (pending)
* fenv.hh
* fmtmsg.hh
* fnmatch.hh
* ftw.hh
* glob.hh
* grp.hh
* iconv.hh
* inttypes.hh
* langinfo.hh
* libgen.hh
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
* setjmp.hh
* signal.hh
* spawn.hh
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
  * sem.hh
  * shm.hh
  * socket.hh
    * Core Wrapper (done)
    * Custom implementation to manage socket handles (done)
    * Interface using socket container (pending)
  * stat.hh
  * stavfs.hh
  * time.hh
  * timeb.hh
  * times.hh
  * uio.hh
  * un.hh
  * utsname.hh
  * wait.hh
* syslog.hh
* termios.hh
* tgmath.hh
* time.hh
* trace.hh
* ucontext.hh
* ulimit.hh
* unistd.hh
  * Core Wrapper (done)
  * Custom implementation to manage file handles (done)
  * Interface using file handle container (pending)
* fildes.hh
  * Custom implementation to manage file handles (pending)
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
Run `make -B docs` to generate up-to-date documentation.

### Using

You will need to include the relevant headers as you would for the libc alternatives

```
For example:

> `#include <semaphore.h>`

is now

> `#include <semaphore.hh>`
```

This *does not include* files which merely contain macro values or functions

Note that the CXX headers will also include the libc equivalent also without adulterations.

You will need to link your binaries with `posicxx.a` at compile-time

See `docs/` for documentation.

***

See LICENSE for terms of usage.

