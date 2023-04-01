#include <cerrno> // allows access to errno variable
#include <cstring>
#include <string>

#include "error.hh"

/**
 * @brief error.cc - file serves as CXX-style, exception-driven wrapper of POSIX C's error-code reporting mechanism
 * This file contains the definitions of such
 * For internal use only
 */

posicxx::Error::Error(const int errno_n) noexcept :
	std::runtime_error( // give runtime_error an error message
		[&]() -> std::string
		{
			/* if any of these cause an error, let it crash the system */
			std::string error_str ;

			if(errno_n != POSICXX_UNDEFINED_ERROR)
			{
				error_str = std::to_string(errno_n) ;
				error_str += std::string(": ") ;
				error_str += std::strerror(errno_n) ;
			}
			else {
				error_str = std::string("Undefined error") ;
			}

			error_str += std::string(". Please refer to the appropriate manual / documentation") ;

			return error_str ;
		}() // remember to actually trigger a call to the function
	),
	_errno(errno_n) // keep the errno for future reference
{}

int posicxx::Error::operator()() const noexcept
{
	return this->_errno ;
}
