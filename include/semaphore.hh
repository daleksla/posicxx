#ifndef SEMAPHORE_HH
#define SEMAPHORE_HH
#pragma once

#include <semaphore.h>

/**
 * @brief semaphore.hh - file serves as CXX declarations of POSIX semaphore functionality, containing the minimal wrapper and the fancy interface
 * See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/semaphore.h.html for general details
 */

namespace posicxx {

	/**
	 * @brief sem_close - closes named semaphore
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_close.html for more details
	 *
	 * @param sem_t* sem - named semaphore to close
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void sem_close(sem_t* sem) noexcept(false) ;
	
	/**
	 * @brief sem_destroy - destroys unnamed semaphore
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_destroy.html for more details
	 *
	 * @param sem_t* sem - unnamed semaphore to destroy
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void sem_destroy(sem_t* sem) noexcept(false) ;

	/**
	 * @brief sem_getvalue - gets current value of semaphore
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_getvalue.html for more details
	 *
	 * @param sem_t* sem - semaphore to get current value of
	 * @param int* sval - destination of current semaphore value
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void sem_getvalue(sem_t* sem, int* sval) noexcept(false) ;

	/**
	 * @brief sem_init - initialises unnamed semaphore
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_init.html for more details
	 *
	 * @param sem_t* sem - unnamed semaphore to initialise
	 * @param int pshared - whether semaphore should be shared between threads of a process only or between multiple processes
	 * @param unsigned int value - specifies initial value for semaphore
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void sem_init(sem_t* sem, int pshared, unsigned int value) noexcept(false) ;

	/**
	 * @brief sem_open (overload) - creates a named POSIX semaphore / opens an existing semaphore
	 * I've made a concious decision to implement this function as two overloads (rather than a variadic argument) in the cases where you need to given additional arguments beyond the first 2 (name, oflags)
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_open.html for more details
	 *
	 * @param const char* name - name of semaphore
	 * @param int oflags - flags to control operation of the call
	 * Possible arguments can be found in fcntl.h
	 *
	 * @return sem_t* - address of the new semaphore
	 * Will not be SEM_FAILED (or NULL / nullptr or whatever) as as exception will be thrown if this is the case
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	sem_t* sem_open(const char* name, int oflags) noexcept(false) ;

	/**
	 * @brief sem_open (overload) - creates a named POSIX semaphore / opens an existing semaphore
	 * I've made a concious decision to implement this function as two overloads (rather than a variadic argument) in the cases where you need to given additional arguments beyond the first 2 (name, oflags)
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_open.html for more details
	 *
	 * @param const char* name - name of semaphore
	 * @param int oflags - flags to control operation of the call
	 * Possible arguments can be found in fcntl.h
	 *
	 * There are two additional arguments if the 'oflags' arguments matches the O_CREAT and semaphore being created is indeed new
	 	* @param mode_t mode - specifies permissions for new semaphore
	 	* Possible arguments can be found in sys/stat.h
	 	*
		* @param unsigned int value - specifies initial value for new semaphore
	 *
	 * @return sem_t* - address of the new semaphore
	 * Will not be SEM_FAILED (or NULL / nullptr or whatever) as as exception will be thrown if this is the case
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	sem_t* sem_open(const char* name, int oflags, mode_t mode, unsigned int value) noexcept(false) ;

	/**
	 * @brief sem_post - unlocks a semaphore
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_post.html for more details
	 *
	 * @param sem_t* sem - semaphore to unlock
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void sem_post(sem_t* sem) noexcept(false) ;

	/**
	 * @brief sem_timedwait - attempts to lock a semaphore with timeout
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_timedwait.html for more details
	 *
	 * @param sem_t* sem - semaphore
	 * @param const struct timespec* abs_timeout - specifies absolute timeout in s / ns since the Epoch
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
#if _POSIX_C_SOURCE >= 200112L
	void sem_timedwait(sem_t* sem, const struct timespec* abs_timeout) noexcept(false) ;
#endif // #if _POSIX_C_SOURCE >= 200112L

	/**
	 * @brief sem_trywait - attempts to lock a semaphore without blocking
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_trywait.html for more details
	 *
	 * @param sem_t* sem - semaphore
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void sem_trywait(sem_t* sem) noexcept(false) ;

	/**
	 * @brief sem_unlink - removes a named semaphore
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_unlink.html for more details
	 *
	 * @param const char* name - name of semaphore
	 *
	 * @throws posicxx:Error - exception thrown upon error
	 */
	void sem_unlink(const char* name) noexcept(false) ;

	/**
	 * @brief sem_wait - attempts to lock a semaphore, blocking if not possible currently
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sem_wait.html for more details
	 *
	 * @param sem_t* sem - semaphore
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void sem_wait(sem_t* sem) noexcept(false) ;

}

#endif // #ifndef SEMAPHORE_HH
