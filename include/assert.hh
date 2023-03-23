#ifndef ASSERT_HH
#define ASSERT_HH
#pragma once

#include <assert.h>

/**
 * @brief assert.hh - file serves as CXX declarations of POSIX assert functionality, containing the minimal wrapper only
 * See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/assert.h.html for general details
 */

namespace posicxx {

	/**
	 * @brief assert - insert program diagnostics
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/assert.html for more details
	 *
	 * @param bool expression - scalar expression which can be determined to be of a true / false value
	 */
	void assert(const bool expression) noexcept ;

}

#endif // ASSERT_HH
