#ifndef SYS_SOCKET_HH
#define SYS_SOCKET_HH
#pragma once

#include <sys/socket.h>

#include "unistd.hh"

/**
 * @brief sys/socket.hh - file serves as CXX declarations of POSIX socket functionality, containing the minimal wrapper, fancy interface and resource manager
 * See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/socket.h.html for general details
 */

namespace posicxx {

	/**
	 * @brief Socket (class) - class to open, close and manage file descriptors
	 * Inherits from Fildes class, as a socket can do everything a classic file descriptor can but not vice versa - allows us to perform polymorphism
	 */
	class Socket : public Fildes {
		public:
			/**
			 * @brief Socket (constructor) - inherits and assumes control of a socket
			 */
			Socket(const int sock) noexcept(false) ;

			/**
			 * @brief Socket (constructor) - opens socket
			 * A stub to posicxx::socket() - refer to it for more detail
			 *
			 * @param int domain - communications domain in which a socket is created
			 *
			 * @param int type - type of socket intended
			 *
			 * @param int protocol - protocol to be used with socket
			 * 0 causes default protocol for given socket type to be selected
			 *
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Socket(int domain, int type, int protocol) noexcept(false) ;

			/**
			 * @brief Socket (copy constructor) - copies socket
			 * @param const Socket& sock - socket to copy
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Socket(const Socket& sock) noexcept(false) ;

			/**
			 * @brief operator= (copy assignment) - copies socket
			 * @param const Socket& sock - socket to copy
			 * @return Socket& - reference to created socket
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Socket& operator=(const Socket& sock) noexcept(false) ;

			/**
			 * @brief Socket (move constructor) - acqires socket
			 * @param Socket&& sock - socket to acquire
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Socket(Socket&& sock) noexcept(false) ;

			/**
			 * @brief operator= (move assignment) - acqires socket
			 * @param Socket&& sock - socket to acquire
			 * @return Socket& - reference to created socket
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Socket& operator=(Socket&& sock) noexcept(false) ;

			/**
			 * @brief Fildes (destructor) - closes file handle
			 * A stub to posicxx::close - refer to it for more detail
			 * Virtual to allow inheritance
			 */
			~Socket() noexcept ;

			/* Below are the defaulted and deleted methods */
			Socket() noexcept = delete ;

	} ;

	/**
	 * @brief accept - accepts a new connection on a socket
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/accept.html for more details
	 *
	 * @param int socket - bound socket awaiting connections
	 * @param struct sockaddr* addr - the address of the connecting socket
	 * @param socklen_t* addrlen - on input: specifies the length of the supplied sockaddr structure; on output: specifies the length of the stashed address
	 *
	 * @return int - positive integer file handle
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen) noexcept(false) ;

	/**
	 * @brief bind - binds a local name to a socket
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/bind.html for more details
	 *
	 * @param int socket - bound socket awaiting connections
	 * @param const struct sockaddr* addr - address of the socket which we are trying to bind socket to
	 * @param socklen_t* addrlen - length of the supplied sockaddr structure
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen) noexcept(false) ;

	/**
	 * @brief connect - attempts to connect to endpoint of socket
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/connect.html for more details
	 *
	 * @param int socket - bound socket awaiting connections
	 * @param const struct sockaddr* addr - peer address we're connecting to
	 * @param socklen_t* addrlen - length of the supplied sockaddr structure
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen) noexcept(false) ;

	/**
	 * @brief getpeername - gets details with regards to peer-end of socket
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getpeername.html for more details
	 *
	 * @param int socket - socket to get peername from
	 * @param struct sockaddr* addr - where to store peer details
	 * @param socklen_t* addrlen - length of the stashed sockaddr structure
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void getpeername(int sockfd, struct sockaddr* addr, socklen_t* addrlen) noexcept(false) ;

	/**
	 * @brief getsockname - gets local protocol details of socket
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getsockname.html for more details
	 *
	 * @param int socket - socket to get peername from
	 * @param struct sockaddr* addr - where to store local protocol details
	 * @param socklen_t* addrlen - length of the stashed sockaddr structure
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void getsockname(int sockfd, struct sockaddr* addr, socklen_t* addrlen) noexcept(false) ;

	/**
	 * @brief getsockopt - get specified socket option
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getsockopt.html for more details
	 *
	 * @param int sockfd - socket to get configurations of
	 * @param int level - specifies the protocol level where the option resides
	 * @param int optname - actual option
	 * @param void* optval - destination to store result of socket option
	 * @param socklen_t* optlen - length of the stashed socket option
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void getsockopt(int sockfd, int level, int optname, void* optval, socklen_t* optlen) noexcept(false) ;

	/**
	 * @brief listen - listen & queue (a capped) incoming connections
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getsockopt.html for more details
	 *
	 * @param int sockfd - connection-configured socket
	 * @param int backlog - limit of incoming, unserviced connections
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void listen(int sockfd, int backlog) noexcept(false) ;

	/**
	 * @brief recv - receive a message from a connection-mode socket
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/recv.html for more details
	 *
	 * @param int sockfd - connection-configured socket
	 * @param void* buf - message destination
	 * @param size_t len - length of supplied buffer
	 * @param int flags - specifies type of message reception
	 *
	 * @return ssize_t - length of message stashed
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t recv(int sockfd, void* buf, size_t len, int flags) noexcept(false) ;

	/**
	 * @brief recvfrom - receive a message from a connection-mode or connectionless-mode socket, providing source details
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/recvfrom.html for more details
	 *
	 * @param int sockfd - connection-configured socket
	 * @param void* buf - message destination
	 * @param size_t len - length of buffer
	 * @param int flags - specifies type of message reception
	 * @param struct sockaddr* src_addr - where the peers address is to be stashed
	 * @param socklen_t* addrlen - length of the stashed sockaddr structure
	 *
	 * @return ssize_t - length of stashed message
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t recvfrom(int sockfd, void* buf, size_t len, int flags, struct sockaddr* src_addr, socklen_t* addrlen) noexcept(false) ;

	/**
	 * @brief recvmsg - receive a message from a connection-mode or connectionless-mode socket, providing source details & finer buffer control
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/recvmsg.html for more details
	 *
	 * @param int sockfd - connection-configured socket
	 * @param struct msghdr* msg - buffer for source information and message contents
	 * @param int flags - specifies type of message reception
	 *
	 * @return ssize_t - length of message stashed
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t recvmsg(int sockfd, struct msghdr* msg, int flags) noexcept(false) ;

	/**
	 * @brief send - sends a message from a connection-mode socket
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/send.html for more details
	 *
	 * @param int sockfd - connection-configured socket
	 * @param const void* buf - message source
	 * @param size_t len - length of supplied buffer
	 * @param int flags - specifies type of message reception
	 *
	 * @return ssize_t - length of message supplied and sent
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t send(int sockfd, const void* buf, size_t len, int flags);

	/**
	 * @brief sendto - sends a message on a connection-mode or connectionless-mode socket
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sendto.html for more details
	 *
	 * @param int sockfd - connection-configured socket
	 * @param const void* buf - message source
	 * @param size_t len - length of supplied message
	 * @param int flags - specifies type of message transmission
	 * @param const struct sockaddr* dest_addr - where the peers address is supplied
	 * @param socklen_t addrlen - length of the supplied sockaddr structure
	 *
	 * @return ssize_t - length of message supplied and sent
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t sendto(int sockfd, const void* buf, size_t len, int flags, const struct sockaddr* dest_addr, socklen_t addrlen) noexcept(false) ;

	/**
	 * @brief sendmsg - sends a message from a connection-mode or connectionless-mode socket, providing destination details & finer buffer control
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sendmsg.html for more details
	 *
	 * @param int sockfd - connection-configured socket
	 * @param struct msghdr* msg - buffer for destination information and message contents
	 * @param int flags - specifies type of message transmission
	 *
	 * @return ssize_t - length of message supplied and sent
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t sendmsg(int sockfd, const struct msghdr* msg, int flags) noexcept(false) ;

	/**
	 * @brief setsockopt - sets specified socket option
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setsockopt.html for more details
	 *
	 * @param int sockfd - socket to set configurations of
	 * @param int level - specifies the protocol level where the option resides
	 * @param int optname - actual option
	 * @param void* optval - destination to store result of socket option
	 * @param socklen_t* addrlen - length of the stashed socket option
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void setsockopt(int sockfd, int level, int optname, const void* optval, socklen_t optlen) noexcept(false) ;

	/**
	 * @brief shutdown - shut down sockets future send and receive operations
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/shutdown.html for more details
	 *
	 * @param int sockfd - socket descriptor
	 * @param int how - specifies type of shutdown
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void shutdown(int sockfd, int how) noexcept(false) ;

	/**
	 * @brief socket - creates endpoint for communication
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/socket.html for more details
	 *
	 * @param int domain - communications domain in which a socket is created
	 *
	 * @param int type - type of socket intended
	 *
	 * @param int protocol - protocol to be used with socket
	 * 0 causes default protocol for given socket type to be selected
	 *
	 * @return int - positive integer file handle
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int socket(int domain, int type, int protocol) noexcept(false) ;

#if _POSIX_C_SOURCE >= 200112L
	/**
	 * @brief sockatmark - determine whether a socket is at the out-of-band mark
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sockatmark.html for more details
	 *
	 * @param int sockfd - socket to check
	 *
	 * @return int - boolean as to whether data is at the out-of-band mark (i.e. 1 if yes, 0 if no)
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int sockatmark(int sockfd) noexcept(false) ;
#endif // #if _POSIX_C_SOURCE >= 200112L

	/**
	 * @brief socketpair - create a pair of connected sockets
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/socketpair.html for more details
	 *
	 * @param int domain - communications domain in which a socket is created
	 *
	 * @param int type - type of socket intended
	 *
	 * @param int protocol - protocol to be used with socket
	 * 0 causes default protocol for given socket type to be selected
	 *
	 * @param int sv[2] - array capable of storing 2+ integers to stash created sockets
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void socketpair(int domain, int type, int protocol, int sv[2]) noexcept(false) ;

}

#endif // #ifndef SYS_SOCKET_HH
