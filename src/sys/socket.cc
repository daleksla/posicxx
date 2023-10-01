#include "posixver.hh" // MUST BE INCLUDED FIRST in SRC files

#include <system_error>

#include "sys/socket.hh"

/**
 * @brief sys/socket.cc - file serves as CXX definitions of POSIX socket functionality, containing the minimal wrapper, fancy interface and resource manager
 */

int posicxx::accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen) noexcept(false) 
{
	const int fd = ::accept(sockfd, addr, addrlen) ;
	if(fd < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return fd ;
}

void posicxx::bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen) noexcept(false) 
{
	if(::bind(sockfd, addr, addrlen) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

void posicxx::connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen) noexcept(false) 
{
	if(::connect(sockfd, addr, addrlen) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

void posicxx::getpeername(int sockfd, struct sockaddr* addr, socklen_t* addrlen) noexcept(false) 
{
	if(::getpeername(sockfd, addr, addrlen) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

void posicxx::getsockname(int sockfd, struct sockaddr* addr, socklen_t* addrlen) noexcept(false) 
{
	if(::getsockname(sockfd, addr, addrlen) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

void posicxx::getsockopt(int sockfd, int level, int optname, void* optval, socklen_t* optlen) noexcept(false) 
{
	if(::getsockopt(sockfd, level, optname, optval, optlen) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

void posicxx::listen(int sockfd, int backlog) noexcept(false) 
{
	if(::listen(sockfd, backlog) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

ssize_t posicxx::recv(int sockfd, void* buf, size_t len, int flags) noexcept(false) 
{
	const ssize_t len2 = ::recv(sockfd, buf, len, flags) ;
	if(len2 < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return len2 ;
}

ssize_t posicxx::recvfrom(int sockfd, void* buf, size_t len, int flags, struct sockaddr* src_addr, socklen_t* addrlen) noexcept(false) 
{
	const ssize_t len2 = ::recvfrom(sockfd, buf, len, flags, src_addr, addrlen) ;
	if(len2 < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return len2 ;
}

ssize_t posicxx::recvmsg(int sockfd, struct msghdr* msg, int flags) noexcept(false) 
{
	const ssize_t len = ::recvmsg(sockfd, msg, flags) ;
	if(len < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return len ;
}

ssize_t posicxx::send(int sockfd, const void* buf, size_t len, int flags)
{
	const ssize_t len2 = ::send(sockfd, buf, len, flags) ;
	if(len2 < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return len2 ;
}

ssize_t posicxx::sendto(int sockfd, const void* buf, size_t len, int flags, const struct sockaddr* dest_addr, socklen_t addrlen) noexcept(false) 
{
	const ssize_t len2 = ::sendto(sockfd, buf, len, flags, dest_addr, addrlen) ;
	if(len2 < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return len2 ;
}

ssize_t posicxx::sendmsg(int sockfd, const struct msghdr* msg, int flags) noexcept(false) 
{
	const ssize_t len = ::sendmsg(sockfd, msg, flags) ;
	if(len < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return len ;
}

void posicxx::setsockopt(int sockfd, int level, int optname, const void* optval, socklen_t optlen) noexcept(false) 
{
	if(::setsockopt(sockfd, level, optname, optval, optlen) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

void posicxx::shutdown(int sockfd, int how) noexcept(false) 
{
	if(::shutdown(sockfd, how) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}

int posicxx::socket(int domain, int type, int protocol) noexcept(false) 
{
	const int sock = ::socket(domain, type, protocol) ;
	if(sock < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return sock ;
}

int posicxx::sockatmark(int sockfd) noexcept(false)
{
	const int atmark = ::sockatmark(sockfd) ;
	if(atmark < 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
	return atmark ;
}

void posicxx::socketpair(int domain, int type, int protocol, int sv[2]) noexcept(false) 
{
	if(::socketpair(domain, type, protocol, sv) != 0)
	{
		throw std::system_error(errno, std::generic_category()) ;
	}
}
