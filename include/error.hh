#ifndef ERROR_HH
#define ERROR_HH
#pragma once

#include <cerrno>

#include <stdexcept>

/**
 * @brief error.hh - file serves as CXX-style, exception-driven wrapper of POSIX C's error-code reporting mechanism
 * This file contains the declarations of such
 */

namespace posicxx {

#define POSICXX_UNDEFINED_ERROR -1

	/**
	 * @brief Error (class) - class thrown to manifest POSIX system errnos using CXX exceptions
	 */
	class Error : public std::runtime_error {
		private:
			int _errno ; // error number being thrown

		public:
			/**
			 * @brief Error (constructor) - initialises errno value and exception message
			 *
			 * @param const int errno - valid errno, as possibly returned by syscalls
			 * See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/errno.h.html for more details
			 *
			 */
			Error(const int errno_n) noexcept ;

			/**
			 * @brief operator() - returns errno which error is made for
			 * @return int - the internal errno
			 */
			int operator()() const noexcept ;

			/* Below are the defaulted and deleted methods */
			Error() noexcept = delete ;
			Error(const Error& error) noexcept = default ;
			Error& operator=(const Error& error) noexcept = default ;
			Error(Error&& error) noexcept = default ;
			Error& operator=(Error&& error) noexcept = default ;
			~Error() noexcept = default ;
	} ;

}

#endif // #ifndef ERROR_HH
