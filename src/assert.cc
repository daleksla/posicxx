#include <assert.h>

#include "assert.hh"

/**
 * @brief assert.cc - file serves as CXX definitions of posicxx's minimal wrapper assert functionality
 * For internal use only
 */

void posicxx::assert(const boot expression) noexcept
{
	::assert(expression);
}
