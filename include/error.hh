#ifndef ERROR_HH
#define ERROR_HH
#pragma once

#include <stdexcept>

#include <errno.h> // allows access to errno variable

/**
 * @brief error.cc - file serves as CXX-style, exception-driven wrapper of POSIX C's error-code reporting mechanism
 * This file contains the declarations of such
 */

namespace posicxx {

	class Error : public std::runtime_error {
		public:
			/**
			 * @brief Error (constructor) - initialises values of exception
			 *
			 * @param const int errno - valid errno, as possibly returned by syscalls
			 * See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/errno.h.html for more details
			 */
			Error(const int errno_n) noexcept ;

			/* Below are the defaulted and deleted methods */
			Error() noexcept = delete ;
			Error(const Error& error) noexcept = default ;
			Error& operator=(const Error& error) noexcept = default ;
			Error(Error&& error) noexcept = default ;
			Error& operator=(Error&& error) noexcept = default ;
			~Error() noexcept = default ;
	};

}

#endif // ERROR_HH
