#ifndef STDLIB_HH
#define STDLIB_HH
#pragma once

/**
 * @brief stdlib.hh - file serves as CXX declarations of POSIX standard library definitions, containing the minimal wrapper, fancy interface and resource manager
 * See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/stdlib.h.html for general details
 */

namespace posicxx {

	/**
	 * @brief _Exit - terminates a process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/_exit.html for more details
	 *
	 * @param int status - exit code
	 */
	void _Exit(int status) noexcept ;

	/**
	 * @brief a64l - convert a radix-64 ASCII string to a 32-bit integer
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/a64l.html for more details
	 *
	 * @param const char* s - string to convert
	 *
	 * @return long - interpreted string to int
	 */
	long a64l(const char* s) noexcept ;

	/**
	 * @brief abort - generates an abnormal process abort
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/abort.html for more details
	 */
	void abort() noexcept ;

	/**
	 * @brief abs - returns the absolute value of an integer
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/abs.html for more details
	 *
	 * @param int i - value to return absolute interpretation of
	 *
	 * @return int - absolute value of argumenet `i`
	 */
	int abs(int i) noexcept ;

	/**
	 * @brief atexit - registers a function to run at process termination
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/atexit.html for more details
	 *
	 * @param void (*func)() - function to run at process' termination
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void atexit(void (*func)()) noexcept(false) ;

	/**
	 * @brief atof - converts a string to a double-precision number
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/atof.html for more details
	 *
	 * @param const char* str - string to convert to double-precision
	 *
	 * @return double - interpreted contents of string
	 */
	double atof(const char* str) noexcept ;

	/**
	 * @brief atoi - converts a string to a integer
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/atoi.html for more details
	 *
	 * @param const char* str - string to convert to double-precision
	 *
	 * @return int - interpreted contents of string
	 */
	int atoi(const char* str) noexcept ;

	/**
	 * @brief atol - converts a string to a long integer number
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/atol.html for more details
	 *
	 * @param const char* str - string to convert to double-precision
	 *
	 * @return long - interpreted contents of string
	 */
	long atol(const char* str) noexcept ;

	/**
	 * @brief atoll - converts a string to a long long integer number
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/atoll.html for more details
	 *
	 * @param const char* str - string to convert to double-precision
	 *
	 * @return long long - interpreted contents of string
	 */
	long long atoll(const char* str) noexcept ;

	/**
	 * @brief bsearch - binary search a sorted table
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/bsearch.html for more details
	 *
	 * @param const void* key - value of object to search for
	 * @param const void* base - start of table
	 * @param size_t nel - size of array
	 * @param size_t width - size of each element of array
	 * @param int (*compar)(const void*, const void*) - function pointer to compare `key` arguement and an element of the table
	 *
	 * @return long long - interpreted contents of string
	 */
	void* bsearch(const void* key, const void* base, size_t nel, size_t width, int (*compar)(const void*, const void*)) noexcept ;

	/**
	 * @brief calloc - allocates dynamic memory
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/calloc.html for more details
	 *
	 * @param size_t nelem - number of elements
	 * @param size_t elsize - size of each element
	 *
	 * @return void* - pointer to start of allocated memory
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void* calloc(size_t nelem, size_t elsize) noexcept(false) ;

	/**
	 * @brief div - computes the quotient and remainder of an integer division
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/div.html for more details
	 *
	 * @param int numer - dividend
	 * @param int denom - divisor
	 *
	 * @return div_t - structure comprising of both the quotient and the remainder
	 */
	div_t div(int numer, int denom) noexcept ;

	/**
	 * @brief erand48 - generates a uniformly distributed pseudo-random double-precision number
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/drand48.html for more details
	 *
	 * @pre srand48() *or* seed48() *or* lcong48() - initialisation entry points
	 *
	 * @return double - random, non-negative, double-precision floating point value between 0.0 -> 1.0
	 */
	double drand48() noexcept ;

	/**
	 * @brief erand48 - generates a uniformly distributed pseudo-random double-precision number
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/erand48.html for more details
	 *
	 * @param unsigned short xsubi[3] - array to be used as part of internal algorithm
	 *
	 * @return double - random, non-negative, double-precision floating point value between 0.0 -> 1.0
	 */
	double erand48(unsigned short xsubi[3]) noexcept ;

	/**
	 * @brief exit - terminates a process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/exit.html for more details
	 *
	 * @param int status - exit code
	 */
	void exit(int status) noexcept ;

	/**
	 * @brief free - frees allocated memory
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/free.html for more details
	 *
	 * @param void* ptr - pointer to start of to-be-deallocated block
	 */
	void free(void* ptr) noexcept ;

	/**
	 * @brief getenv - gets the value of an environment variable
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getenv.html for more details
	 *
	 * @param const char* name - name of environmental variable to get value of
	 *
	 * @return char* - pointer to a string containing the value for the specified name
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	char* getenv(const char* name) noexcept(false) ;

	/**
	 * @brief getsubopt - parses suboption arguments from a string
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getsubopt.html for more details
	 *
	 * @param char** optionp - pointer to c-string / pointer to option argument string
	 * @param char* const* keylistp - pointer to a NULL-terminated vector of string
	 * @param char** valuep - address of a value string pointer
	 *
	 * @return int - index of the matched token string
	 */
	int getsubopt(char** optionp, char* const* keylistp, char** valuep) noexcept ;

	/**
	 * @brief grantpt - grant access to the slave pseudo-terminal device
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/grantpt.html for more details
	 *
	 * @param int fildes - open file descriptor
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void grantpt(int fildes) noexcept(false) ;

	/**
	 * @brief initstate - initialises random-number generators
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/initstate.html for more details
	 *
	 * @param unsigned seed - starting point for random number sequence
	 * @param char* state - state array to be initialised
	 * @param size_t size - size of array `state` - should be either 8, 32, 64, 128, 256 bytes.
	 *
	 * @return char* - previous state array
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	char* initstate(unsigned seed, char* state, size_t size) noexcept(false) ;

	/**
	 * @brief jrand48 - generates a uniformly distributed pseudo-random signed long number
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/jrand48.html for more details
	 *
	 * @param unsigned short xsubi[3] - array to be used as part of internal algorithm
	 *
	 * @return long - random signed long integer value between -2^33 -> 2^33
	 */
	long jrand48(unsigned short xsubi[3]) noexcept ;

	/**
	 * @brief l64a - convert a 32-bit integer to a radix-64 ASCII string
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/l64a.html for more details
	 *
	 * @param long value - value to convert
	 *
	 * @return char* - converted string
	 */
	char* l64a(long value) noexcept ;

	/**
	 * @brief labs - returns the absolute value of a long integer
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/labs.html for more details
	 *
	 * @param long i - value to return absolute interpretation of
	 *
	 * @return long - absolute value of argumenet `i`
	 */
	long labs(long i) noexcept ;

	/**
	 * @brief lcong48 - initialises random-number generators
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/lcong48.html for more details
	 *
	 * @param unsigned short param[7] - elements 0-2 specify initial X , elements 3-5 specify the multiplier a, element 6 specifies the 16-bit addend c
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void lcong48(unsigned short param[7]) noexcept(false) ;

	/**
	 * @brief ldiv - computes the quotient and remainder of a long integer division
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/ldiv.html for more details
	 *
	 * @param long int numer - dividend
	 * @param long int denom - divisor
	 *
	 * @return ldiv_t - structure comprising of both the quotient and the remainder
	 */
	ldiv_t ldiv(long numer, long denom) noexcept ;

	/**
	 * @brief llabs - returns the absolute value of a long long integer
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/llabs.html for more details
	 *
	 * @param long long i - value to return absolute interpretation of
	 *
	 * @return long long - absolute value of argumenet `i`
	 */
	long long llabs(long long i) noexcept ;

	/**
	 * @brief lldiv - computes the quotient and remainder of a long long integer division
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/lldiv.html for more details
	 *
	 * @param long long int numer - dividend
	 * @param long long int denom - divisor
	 *
	 * @return ldiv_t - structure comprising of both the quotient and the remainder
	 */
	lldiv_t lldiv(long long numer, long long denom) noexcept(false) ;

	/**
	 * @brief lrand48 - generates a uniformly distributed pseudo-random unsigned long number
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/lrand48.html for more details
	 *
	 * @pre srand48() *or* seed48() *or* lcong48() - initialisation entry points
	 *
	 * @return long - random unsigned long integer value between 0 -> 2^33
	 */
	long lrand48() noexcept ;

	/**
	 * @brief malloc - allocates dynamic memory
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/malloc.html for more details
	 *
	 * @param size_t size - number of bytes to allocate
	 *
	 * @return void* - pointer to start of allocated memory
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void* malloc(size_t size) noexcept(false) ;

	int mblen(const char*, size_t) noexcept(false) ;

	size_t mbstowcs(wchar_t*, const char*, size_t) noexcept(false) ;

	int mbtowc(wchar_t*, const char*, size_t) noexcept(false) ;

	char* mkdtemp(char* ) noexcept(false) ;

	int mkstemp(char* ) noexcept(false) ;

	long mrand48() noexcept(false) ;

	long nrand48(unsigned short [3]) noexcept(false) ;

	int posix_memalign(void**, size_t, size_t) noexcept(false) ;

	int posix_openpt(int) noexcept(false) ;

	char* ptsname(int) noexcept(false) ;

	int putenv(char* ) noexcept(false) ;

	void qsort(void*, size_t, size_t, int (*)(const void*, const void* )) noexcept(false) ;

	int rand() noexcept(false) ;

	int rand_r(unsigned* ) noexcept(false) ;

	long random() noexcept(false) ;

	/**
	 * @brief realloc - reallocates dynamic memory
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/realloc.html for more details
	 *
	 * @param void* ptr - pointer to existing space
	 * @param size_t size - intended new number of bytes to have allocated
	 *
	 * @return void* - pointer to start of expanded or moved allocated memory
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void* realloc(void* ptr, size_t size) noexcept(false) ;

	char* realpath(const char*, char* ) noexcept(false) ;

	/**
	 * @brief seed48 - initialises random-number generators
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/seed48.html for more details
	 *
	 * @param unsigned short seed16v[3] - new value of initial X
	 * The low-order 16 bits of Xi are set to the low-order 16 bits of seed16v[0]. The mid-order 16 bits of Xi are set to the low-order 16 bits of seed16v[1]. The high-order 16 bits of Xi are set to the low-order 16 bits of seed16v[2]
	 *
	 * @return unsigned short* - last X value
	 */
	unsigned short* seed48(unsigned short seed16v[3]) noexcept ;

	int setenv(const char*, const char*, int) noexcept(false) ;

	void setkey(const char* ) noexcept(false) ;

	char* setstate(char* ) noexcept(false) ;

	/**
	 * @brief srand - pseudo-random number generator
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/srand.html for more details
	 *
	 * @param unsigned seed - seed for new sequence of pseudo-random numbers
	 */
	void srand(unsigned seed) noexcept(false) ;

	/**
	 * @brief seed48 - initialises random-number generators
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/seed48.html for more details
	 *
	 * @param long seedval - initial X value
	 * The high-order 32 bits of Xi to the low-order 32 bits contained in its argument. The low-order 16 bits of Xi are set to the arbitrary value 330E16.
	 */
	void srand48(long seedval) noexcept ;

	/**
	 * @brief srand - pseudo-random number function
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/srandom.html for more details
	 *
	 * @param unsigned seed - seed for new sequence of pseudo-random numbers
	 */
	void srandom(unsigned seed) noexcept ;

	double strtod(const char*, char** ) noexcept(false) ;

	float strtof(const char*, char** ) noexcept(false) ;

	long strtol(const char*, char**, int) noexcept(false) ;

	long double strtold(const char*, char** ) noexcept(false) ;

	long long strtoll(const char*, char**, int) noexcept(false) ;

	unsigned long strtoul(const char*, char**, int) noexcept(false) ;

	unsigned long long strtoull(const char*, char**, int) noexcept(false) ;

	/**
	 * @brief system - issues a command
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/system.html for more details
	 *
	 * @param const char* command - command to execute
	 *
	 * @return int - termination status of command
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int system(const char* command) noexcept(false) ;

	int unlockpt(int) noexcept(false) ;

	int unsetenv(const char* ) noexcept(false) ;

	size_t wcstombs(char*, const wchar_t*, size_t) noexcept(false) ;

	int wctomb(char*, wchar_t) noexcept(false) ;

}

#endif // #ifndef STDLIB_HH
