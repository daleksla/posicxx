#include <string.h>

#include "error.hh"

/**
 * @brief error.cc - file serves as CXX-style, exception-driven wrapper of POSIX C's error-code reporting mechanism
 * This file contains the definitions of such
 * For internal use only
 */

posicxx::Error::Error(const int errno_n) noexcept :
	std::runtime_error(
		static_cast<const char*>(
			strerror(errno_n)
		)
	)
{}
