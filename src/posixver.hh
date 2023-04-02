#ifndef POSIXVER_HH
#define POSIXVER_HH
#pragma once

/**
 * @brief posixver.hh - file serves as to set macros for compiler to expose system functionality
 * For internal use only
 */

/*
** Include this file before including system headers.  By default, with
** C99 support from the compiler, it requests POSIX 2001 support.  With
** C89 support only, it requests POSIX 1997 support.  Override the
** default behaviour by setting either _XOPEN_SOURCE or _POSIX_C_SOURCE.
*/

/* _XOPEN_SOURCE 700 is loosely equivalent to _POSIX_C_SOURCE 200809L */
/* _XOPEN_SOURCE 600 is loosely equivalent to _POSIX_C_SOURCE 200112L */
/* _XOPEN_SOURCE 500 is loosely equivalent to _POSIX_C_SOURCE 199506L */

#if !defined(_XOPEN_SOURCE) && !defined(_POSIX_C_SOURCE)

#if defined(__STDC_VERSION__)
#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 600   // SUS v3, POSIX 1003.1 2004 (POSIX 2001 + Corrigenda)
#else
#define _XOPEN_SOURCE 500   // SUS v2, POSIX 1003.1 1997
#endif // #if __STDC_VERSION__ >= 199901L
#elif defined(__cplusplus)
#define _XOPEN_SOURCE 600
#endif // #ifdef __STDC_VERSION__

#else

#error "Macros _XOPEN_SOURCE and _POSIX_C_SOURCE have already been defined. This header should've been included first"

#endif // #if !defined(_XOPEN_SOURCE) && !defined(_POSIX_C_SOURCE)

#endif // #ifndef POSIXVER_HH
