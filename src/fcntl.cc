#include "posixver.hh" // MUST BE INCLUDED FIRST in SRC files

#include <system_error>

#include "fcntl.hh"

/**
 * @brief fcntl.cc - file serves as CXX definitions of posicxx's file control functionality
 * For internal use only
 */

int posicxx::creat(const char* path, mode_t mode) noexcept(false)
{
	int rcreat = ::creat(path, mode) ;

	if(rcreat < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}

	return rcreat ;
}

int posicxx::fcntl(int fildes, int cmd) noexcept(false)
{
	int rfcntl = ::fcntl(fildes, cmd) ;

	if(rfcntl < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}

	return rfcntl ;
}

int posicxx::fcntl(int fildes, int cmd, const int arg) noexcept(false)
{
	int rfcntl = ::fcntl(fildes, cmd, arg) ;

	if(rfcntl < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}

	return rfcntl ;
}

int posicxx::fcntl(int fildes, int cmd, struct flock const* arg) noexcept(false)
{
	int rfcntl = ::fcntl(fildes, cmd, arg) ;

	if(rfcntl < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}

	return rfcntl ;
}

int posicxx::open(const char* path, int oflag) noexcept(false)
{
	int ropen = ::open(path, oflag) ;

	if(ropen < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}

	return ropen ;
}

int posicxx::open(const char* path, int oflag, const mode_t mode) noexcept(false)
{
	int ropen = ::open(path, oflag, mode) ;

	if(ropen < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}

	return ropen ;
}

void posicxx::posix_fadvise(int fd, off_t offset, off_t len, int advice) noexcept(false)
{
	if(::posix_fadvise(fd, offset, len, advice) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

void posicxx::posix_fallocate(int fd, off_t offset, off_t len) noexcept(false)
{
	if(::posix_fallocate(fd, offset, len) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}
