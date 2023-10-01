#ifndef POSICXX_FCNTL_HH
#define POSICXX_FCNTL_HH
#pragma once

#include <fcntl.h>

/**
 * @brief fcntl.hh - file serves as CXX declarations of POSIX file control functionality, containing the minimal wrapper
 * See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/fcntl.h.html for general details
 */

namespace posicxx {

	/**
	 * @brief creat - creates a new file / rewrites existing one
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/creat.html for more details
	 *
	 * @param const char* path - path to file
	 * @param mode_t mode - permissions for opened file
	 *
	 * @return int - file descriptor to opened file
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int creat(const char* path, mode_t mode) noexcept(false) ;

	/**
	 * @brief fcntl (overload) - file control
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fcntl.html for more details
	 *
	 * @param int fildes - open file descriptor
	 *
	 * @param int cmd - file control command
	 * Relevant commands for this particular overload include F_GETFD, F_GETFL, F_GETOWN, F_SETLK
	 *
	 * @return int - output of specific control command
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int fcntl(int fildes, int cmd) noexcept(false) ;

	/**
	 * @brief fcntl (overload) - file control
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fcntl.html for more details
	 *
	 * @param int fildes - open file descriptor
	 *
	 * @param int cmd - file control command
	 * Relevant commands for this particular overload include F_DUPFD, F_SETFD, F_SETFL, F_SETOWN
	 *
	 * An additional argument exists if such commands are supplied:
		 * @param const int arg - argument required by command provided by `cmd` parameter
	 *
	 * @return int - output of specific control command
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int fcntl(int fildes, int cmd, const int arg) noexcept(false) ;

	/**
	 * @brief fcntl (overload) - file control
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fcntl.html for more details
	 *
	 * @param int fildes - open file descriptor
	 *
	 * @param int cmd - file control command
	 * Relevant commands for this particular overload include F_GETLK, F_SETLK
	 *
	 * An additional argument exists if such commands are supplied:
		 * @param struct flock const* arg - argument required by command provided by `cmd` parameter
	 *
	 * @return int - output of specific control command
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int fcntl(int fildes, int cmd, struct flock const* arg) noexcept(false) ;

	/**
	 * @brief open (overload) - opens a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/open.html for more details
	 *
	 * @param const char* path - path to file
	 * @param int oflag - flag specifying specific file access mode OR'd with additional preferences
	 *
	 * @return int - positive file descriptor
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int open(const char* path, int oflag) noexcept(false) ;

	/**
	 * @brief open (overload) - opens a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/open.html for more details
	 *
	 * @param const char* path - path to file
	 * @param int oflag - flag specifying specific file access mode OR'd with additional preferences
	 *
	 * An additional argument exists if the oflag argument == O_CREAT:
		 * @param const mode_t mode - access permission bits
	 *
	 * @return int - positive file descriptor
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int open(const char* path, int oflag, const mode_t mode) noexcept(false) ;

	/**
	 * @brief posix_fadvise - file access advistory information to application
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/posix_fadvise.html for more details
	 *
	 * @param int fd - open file descriptor
	 * @param off_t offset - offset to data where advisory information applies
	 * @param off_t len - the number of bytes of data from the `offset` argument to which this information applies
	 * @param int advice - the advice argument
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void posix_fadvise(int fd, off_t offset, off_t len, int advice) noexcept(false) ;

	/**
	 * @brief posix_fallocate - file system storage space control
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/posix_fallocate.html for more details
	 *
	 * @param int fd - open file descriptor
	 * @param off_t offset - offset to the start of the data where storage is needed on file system storage media
	 * @param off_t len - the number of bytes of data from the `offset` argument to which the storage is needed for
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void posix_fallocate(int fd, off_t offset, off_t len) noexcept(false) ;

}

#endif // #ifndef POSICXX_FCNTL_HH
