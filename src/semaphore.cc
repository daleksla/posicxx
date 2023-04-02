#include "posixver.hh" // MUST BE INCLUDED FIRST in SRC files

#include "error.hh"

#include "semaphore.hh"

/**
 * @brief semaphore.cc - file serves as CXX definitions of posicxx's minimal wrapper semaphore functionality
 * For internal use only
 */

void posicxx::sem_close(sem_t* sem) noexcept(false)
{
	if(::sem_close(sem) != 0)
	{
		throw posicxx::Error(errno);
	}
}

void posicxx::sem_destroy(sem_t* sem) noexcept(false)
{
	if(::sem_destroy(sem) != 0)
	{
		throw posicxx::Error(errno);
	}
}

void posicxx::sem_getvalue(sem_t* sem, int* sval) noexcept(false)
{
	if(::sem_getvalue(sem, sval) != 0)
	{
		throw posicxx::Error(errno);
	}
}

void posicxx::sem_init(sem_t* sem, int pshared, unsigned int value) noexcept(false)
{
	if(::sem_init(sem, pshared, value) != 0)
	{
		throw posicxx::Error(errno);
	}
}

sem_t* posicxx::sem_open(const char* name, int oflags) noexcept(false)
{
	sem_t* semaphore = ::sem_open(name, oflags) ;
	if(semaphore == SEM_FAILED)
	{
		throw posicxx::Error(errno);
	}
	return semaphore ;
}

sem_t* posicxx::sem_open(const char* name, int oflags, const mode_t mode, const unsigned int value) noexcept(false)
{
	sem_t* semaphore = ::sem_open(name, oflags, mode, value) ;
	if(semaphore == SEM_FAILED)
	{
		throw posicxx::Error(errno);
	}
	return semaphore ;
}

void posicxx::sem_post(sem_t* sem) noexcept(false)
{
	if(::sem_post(sem) != 0)
	{
		throw posicxx::Error(errno);
	}
}

#if _POSIX_C_SOURCE >= 200112L
void posicxx::sem_timedwait(sem_t* sem, const struct timespec* abs_timeout) noexcept(false)
{
	if(::sem_timedwait(sem, abs_timeout) != 0)
	{
		throw posicxx::Error(errno);
	}
}
#endif // #if _POSIX_C_SOURCE >= 200112L

void posicxx::sem_trywait(sem_t* sem) noexcept(false)
{
	if(::sem_trywait(sem) != 0)
	{
		throw posicxx::Error(errno);
	}
}

void posicxx::sem_unlink(const char* name) noexcept(false)
{
	if(::sem_unlink(name) != 0)
	{
		throw posicxx::Error(errno);
	}
}

void posicxx::sem_wait(sem_t* sem) noexcept(false)
{
	if(::sem_wait(sem) != 0)
	{
		throw posicxx::Error(errno);
	}
}
