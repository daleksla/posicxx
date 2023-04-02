#ifndef UNISTD_HH
#define UNISTD_HH
#pragma once

#include <unistd.h>

/**
 * @brief unistd.hh - file serves as CXX declarations of POSIX miscellaneous functionality, containing the minimal wrapper, fancy interface and resource manager
 * See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/unistd.h.html for general details
 */

namespace posicxx {

	/**
	 * @brief Fildes (class) - class to open, close and manage file descriptors
	 */
	class Fildes {
		private:
			int _fd ; // internal file handle

		public:
			/**
			 * @brief Fildes (constructor) - inherits and assumes control of a active file handle
			 * @param const int fd - file descriptor to take control of
			 */
			Fildes(const int fd) noexcept(false) ;

			/**
			 * @brief Fildes (constructor) - opens (classic) file
			 * A stub to posicxx::open - refer to it for more detail
			 *
			 * @param const char* pathname - name of actual file to open
			 * @param int flags - file's access mode
			 * @param mode_t mode - ...
			 *
			 * @throws posicxx::Error - exception thrown upon error
			 *
			 */
			Fildes(const char* pathname, int flags) noexcept(false) ;
			Fildes(const char* pathname, int flags, mode_t mode) noexcept(false) ;

			/**
			 * @brief Fildes (copy constructor) - copies existing file handle
			 * A stub to posicxx::dup() - refer to it for more detail
			 *
			 * @param const Fildes& fd - immutable reference to existing file handle
			 *
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Fildes(const Fildes& fd) noexcept(false) ;

			/**
			 * @brief Fildes (copy assignment) - copies existing file handle
			 * A stub to posicxx::dup() - refer to it for more detail
			 *
			 * @param const Fildes& fd - immutable reference to existing file handle
			 *
			 * @return Files& - reference to created object
			 *
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Fildes& operator=(const Fildes& fd) noexcept(false) ;

			/**
			 * @brief Fildes (move constructor) - acquires existing file handle
			 * @param Fildes&& fd - mutable reference to existing file handle
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Fildes(Fildes&& fd) noexcept(false) ;

			/**
			 * @brief Fildes (move assignment) - acquires existing file handle
			 * @param Fildes&& fd - reference to existing file handle
			 * @return Files& - reference to created object
			 * @throws posicxx::Error - exception thrown upon error
			 */
			Fildes& operator=(Fildes&& fd) noexcept(false) ;

			/**
			 * @brief Fildes (destructor) - closes file handle
			 * A stub to posicxx::close - refer to it for more detail
			 * Virtual to allow inheritance
			 */
			virtual ~Fildes() noexcept ;

			/**
			 * @brief operator() - returns fd
			 * @return int - the internal fd
			 */
			int operator()() const noexcept ;

			/* Below are the defaulted and deleted methods */
			Fildes() noexcept = delete ;
	} ;

	/**
	 * @brief access - determine accessibility of a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/access.html for more details
	 *
	 * @param const char* path - path to file
	 * @param int amode - access permissions to check for
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void access(const char* path, int amode) noexcept(false) ;

	/**
	 * @brief alarm - scheduele an alarm signal
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/alarm.html for more details
	 *
	 * @param unsigned seconds - seconds before SIGALRM is generated
	 *
	 * @return unsigned - number of seconds until any previous request would have generated a SIGALRM signal, else 0
	 */
	unsigned alarm(unsigned seconds) noexcept ;

	/**
	 * @brief chdir - change working directory
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/chdir.html for more details
	 *
	 * @param const char* path - path to file
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void chdir(const char* path) noexcept(false) ;

	/**
	 * @brief chown - change owner and group of a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/chown.html for more details
	 *
	 * @param const char* path - path to file
	 * @param uid_t owner - new desired owner
	 * @param gid_t group - new desired group
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void chown(const char* path, uid_t owner, gid_t group) noexcept(false) ;

	/**
	 * @brief close - closes a file descriptor
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/close.html for more details
	 *
	 * @param int fidles - file descriptor
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void close(int fildes) noexcept(false) ;

	/**
	 * @brief confstr - get configurable variables
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/confstr.html for more details
	 *
	 * @param int name - system variable to be queried
	 * @param char* buf - where configuration-defined strings are to be stashed
	 * @param size_t len - length of buffer
	 *
	 * @return size_t - size of the buffer used to hold entire configuration-defined value (including null terminator)
	 *
	 * @throws posicxx::Error - exception thrown upon error. May or may not have a valid errno depending on the error
	 */
	size_t confstr(int name, char* buf, size_t len) noexcept(false) ;

	/**
	 * @brief crypt - string encoding function (more like hashing)
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/crypt.html for more details
	 * This is just an additional note, but it seems ridiculous to use this in lew of openssl or libressl. It uses DES or MD5 which are both quite weak and more susceptible to modern attacks
	 *
	 * @param const char* key - string to be encoded
	 * @param const char* salt - key containing printable characters
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void crypt(const char* key, const char* salt) noexcept(false) ;

	/**
	 * @brief ctermid - generates a pathname for the controlling terminal
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/ctermid.html for more details
	 *
	 * @param char* s - where, if an array which should be L_ctermid bytes long, the current controlling terminal is to be stashed
	 *
	 * @return char* - pathname to current controlling terminal
	 *
	 * @throws posicxx::Error - exception thrown upon error. Will not have a valid errno as docs do not define it
	 */
	char* ctermid(char* s) noexcept(false) ;

	/**
	 * @brief dup - duplicates an open file descriptor
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/dup.html for more details
	 *
	 * @param int fildes - file descriptor to create alternate descriptor for
	 *
	 * @return int - created file descriptor
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int dup(int fildes) noexcept(false) ;

	/**
	 * @brief dup2 - duplicates an open file descriptor
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/dup2.html for more details
	 *
	 * @param int fildes - file descriptor to create alternate descriptor for
	 * @param int fildes2 - file descriptor to be overwritten and set to be used (hopefully) as file behind fildes argument
	 *
	 * @return int - created file descriptor
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int dup2(int fildes, int fildes2) noexcept(false) ;

	/**
	 * @brief encrypt - encodes using an implementation-defined encoding algorithm
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/encrypt.html for more details
	 *
	 * @pre (posicxx::)setKey() - You'll need to set an encryption key using posicxx::setKey()
	 *
	 * @param char block[64] - array of a minimum length of 64 bytes, containing bytes with the values 0 and 1
	 * @param int edflag - flag regarding whether to encode (0) or decode (1) block argument
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void encrypt(char block[64], int edflag) noexcept(false) ;

	/**
	 * @brief execl - executes a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/execl.html for more details
	 * Note: the exec* family of function in this library aren't stubs - this particular function calls execv
	 *
	 * @param const char* path - path to executable
	 *
	 * @param const char* arg0 - 0th command line argument (e.g. argv[0], typically the program name)
	 *
	 * @param ... - variadic arguments to provide excess arguments
	 * At minimum, this must be used to provide a terminating argument / NULL
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void execl(const char* path, const char* arg0, ...) noexcept(false) ;

	/**
	 * @brief execle - executes a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/execle.html for more details
	 * Note: the exec* family of function in this library aren't stubs - this particular function calls execve
	 *
	 * @param const char* path - path to executable
	 *
	 * @param const char* arg0 - 0th command line argument (e.g. argv[0], typically the program name)
	 *
	 * @param ... - variadic arguments of c-strings, each as an additional arguments
	 * At minimum, this must be used to provide a terminating argument / NULL AND followed by a pointer to a list of environmental variables
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void execle(const char* path, const char* arg0, ...) noexcept(false) ;

	/**
	 * @brief execlp - executes a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/execlp.html for more details
	 * Note: the exec* family of function in this library aren't stubs - this particular function calls execvp
	 *
	 * @param const char* file - executable name
	 * execlp() uses PATH to find executable and therefore doesn't require full path
	 *
	 * @param const char* arg0 - 0th command line argument (e.g. argv[0], typically the program name)
	 *
	 * @param ... - variadic arguments to provide excess arguments
	 * At minimum, this must be used to provide a terminating argument / NULL, followed by a pointer to a list of environmental variables
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void execlp(const char* file, const char* arg0, ...) noexcept(false) ;

	/**
	 * @brief execv - executes a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/execv.html for more details
	 * Note: the exec* family of function in this library aren't stubs - this particular function calls execve
	 *
	 * @param const char* path - executable name
	 * execlp() uses PATH to find executable and therefore doesn't require full path
	 *
	 * @param const char* arg0 - 0th command line argument (e.g. argv[0], typically the program name)
	 *
	 * @param ... - variadic arguments to provide excess arguments
	 * At minimum, this must be used to provide a terminating argument / NULL, followed by a pointer to a list of environmental variables
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void execv(const char* path, char* const argv[]) noexcept(false) ;

	/**
	 * @brief execve - executes a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/execve.html for more details
	 *
	 * @param const char* path - executable name
	 * execvp() uses PATH to find executable and therefore doesn't require full path
	 *
	 * @param char* const argv[] - list of command line arguments
	 * This vector must be terminated by NULL
	 *
	 * @param char* const envp[] - list of environmental variables
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void execve(const char* path, char* const argv[], char* const envp[]) noexcept(false) ;

	/**
	 * @brief execvp - executes a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/execvp.html for more details
	 *
	 * @param const char* path - executable name
	 * execvp() uses PATH to find executable and therefore doesn't require full path
	 *
	 * @param char* const argv[] - list of command line arguments
	 * This vector must be terminated by NULL
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void execvp(const char* file, char* const argv[]) noexcept(false) ;

	/**
	 * @brief _exit - terminates the calling process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/_exit.html for more details
	 *
	 * @param int status - exit code
	 */
	void _exit(int status) noexcept ;

	/**
	 * @brief fchown - change owner and group of a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fchown.html for more details
	 *
	 * @param int fildes - file descriptor to file
	 * @param uid_t owner - new desired owner
	 * @param gid_t group - new desired group
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void fchown(int fildes, uid_t owner, gid_t group) noexcept(false) ;

	/**
	 * @brief fchdir - change working directory
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fchdir.html for more details
	 *
	 * @param int fildes - file descriptor to file
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void fchdir(int fildes) noexcept(false) ;

	/**
	 * @brief fdatasync - synchronises the data of a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fdatasync.html for more details
	 *
	 * @param int fildes - file descriptor to file
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void fdatasync(int fildes) noexcept(false) ;

	/**
	 * @brief fork - creates a new process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fork.html for more details
	 *
	 * @return pid_t - process ID of the child process to the parent process / caller
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	pid_t fork() noexcept(false) ;

	/**
	 * @brief fpathconf - gets configurable pathname variables
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fpathconf.html for more details
	 *
	 * @param int fildes - open file descriptor to get configurable limit / options of
	 * @param int name - the configurable limit / option to get
	 *
	 * @return long - the variable value / limit
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	long fpathconf(int fildes, int name) noexcept(false) ;

	/**
	 * @brief fsync - synchronises changes to a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/fsync.html for more details
	 *
	 * @param int fildes - data to sync
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void fsync(int fildes) noexcept(false) ;

	/**
	 * @brief ftruncate - truncate the size of a given file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/ftruncate.html for more details
	 *
	 * @param int fildes - data to sync
	 * @param off_t length - data to truncate file of (or extend is the file is smaller than given)
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void ftruncate(int fildes, off_t length) noexcept(false) ;

	/**
	 * @brief getcwd - gets the pathname of the current working directory
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getcwd.html for more details
	 *
	 * @param char* buf - buffer to stash name of working directory in
	 * @param size_t size - length of array
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void getcwd(char* buf, size_t size) noexcept(false) ;

	/**
	 * @brief getegid - gets the effective group ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getegid.html for more details
	 *
	 * @return git_t - effective group ID
	 */
	gid_t getegid() noexcept ;

	/**
	 * @brief geteuid - gets the effective user ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/geteuid.html for more details
	 *
	 * @return uit_t - effective user ID
	 */
	uid_t geteuid() noexcept ;

	/**
	 * @brief getgid - gets the real group ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getgid.html for more details
	 *
	 * @return git_t - real group ID
	 */
	gid_t getgid() noexcept ;

	/**
	 * @brief getgroups - gets supplementary group IDs
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getgroups.html for more details
	 *
	 * @param int gidsetsize - number of supplementary group IDs which can be stashed in grouplist argument
	 * @param gid_t grouplist[] - buffer to stash current supplementary groups IDs of the calling process
	 *
	 * @return int - number of group IDs either stashed or would be stashed (latter if gidsetsize == 0)
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int getgroups(int gidsetsize, gid_t grouplist[]) noexcept(false) ;

	/**
	 * @brief gethostid - gets identifier for the current host
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/gethostid.html for more details
	 *
	 * @return long - 32-bit identifierfor the current host
	 */
	long gethostid() noexcept ;

	/**
	 * @brief gethostname - gets name of the current host
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/gethostname.html for more details
	 *
	 * @param char* name - buffer to stash c-string containing hostname
	 * @param size_t namelen - size of buffer
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void gethostname(char* name, size_t namelen) noexcept(false) ;

	/**
	 * @brief getlogin - gets login name
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getlogin.html for more details
	 *
	 * @return char* - name used to login
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	char* getlogin() noexcept(false) ;

	/**
	 * @brief getlogin_r - gets login name
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getlogin_r.html for more details
	 *
	 * @param char* name - buffer to stash login name into
	 * @param size_t namesize - length of buffer provided by argument name
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void getlogin_r(char* name, size_t namesize) noexcept(false) ;

	/**
	 * @brief getopt - command option parsing
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getopt.html for more details
	 *
	 * @param int argc - argument count
	 * @param char* const argv[] - list of arguments
	 * @param const char* optstring - recognised option characters
	 *
	 * @return int - exit code purely related to parsing
	 */
	int getopt(int argc, char* const argv[], const char* optstring) noexcept ;

	/**
	 * @brief getpgid - gets process group ID for a process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getpgid.html for more details
	 *
	 * @param pid_t pid - PID to get group ID of
	 *
	 * @return pid_t - process group ID
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	pid_t getpgid(pid_t pid) noexcept(false) ;

	/**
	 * @brief getpgrp - gets process group ID of calling process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getpgrp.html for more details
	 *
	 * @return pid_t - process group ID
	 */
	pid_t getpgrp() noexcept ;

	/**
	 * @brief getpid - gets process ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getpid.html for more details
	 *
	 * @return pid_t - process ID
	 */
	pid_t getpid() noexcept ;

	/**
	 * @brief getppid - gets parent's process ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getppid.html for more details
	 *
	 * @return pid_t - parent's process ID
	 */
	pid_t getppid() noexcept ;

	/**
	 * @brief getsid - gets process group ID of a session leader
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getsid.html for more details
	 *
	 * @param pid_t pid - PID to get group ID of
	 *
	 * @return pid_t - process group ID of the session leader of the specified process
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	pid_t getsid(pid_t pid) noexcept(false) ;

	/**
	 * @brief getuid - gets a real user ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getuid.html for more details
	 *
	 * @return uid_t - real user ID of the calling process
	 */
	uid_t getuid() noexcept ;

	/**
	 * @brief getwd - gets the current working directory pathname
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/getwd.html for more details
	 * Seriously, don't use this unless you enjoy potential buffer overflows. It's legacy anyhow
	 *
	 * @param char* path_name - buffer to stash absolute pathname of current wd
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void getwd(char* path_name) noexcept(false) ;

	/**
	 * @brief isatty - tests for a terminal device
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/isatty.html for more details
	 * This function does NOT throw an error due to ENOTTY as it's the subject of this function call
	 * Therefore, if it returns false without an exception, it's because !isatty(fildes)
	 *
	 * @param int fildes - file descriptor to potential terminal device
	 *
	 * @return int - boolean result
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int isatty(int fildes) noexcept(false) ;

	/**
	 * @brief lchown - change the owner and group of a symbolic link
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/lchown.html for more details
	 *
	 * @param const char* path - path to symlink
	 * @param uid_t owner - new owner
	 * @param gid_t group - new group
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void lchown(const char* path, uid_t owner, gid_t group) noexcept(false) ;

	/**
	 * @brief link - link a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/link.html for more details
	 *
	 * @param const char* path1 - pathname to existing file
	 * @param const char* path2 - name of directory entry to file indicated by `path1` argument
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void link(const char* path1, const char* path2) noexcept(false) ;

	/**
	 * @brief lockf - record locking on files
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/lockf.html for more details
	 *
	 * @param int fildes - open file descriptor
	 * @param int function - control value (i.e. whether to lock, unlock, etc.)
	 * @param off_t size - number of contiguous bytes to be locked / unlocked
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void lockf(int fildes, int function, off_t size) noexcept(false) ;

	/**
	 * @brief lseek - move the read/write file offset
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/lseek.html for more details
	 *
	 * @param int fildes - open file descriptor
	 * @param off_t offset - number of bytes to offset
	 * @param int whence - how to offset use `offset` argument
	 *
	 * @return off_t - absolute offset from beginning of file
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	off_t lseek(int fildes, off_t offset, int whence) noexcept(false) ;

	/**
	 * @brief nice - change the nice value of a process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/nice.html for more details
	 *
	 * @param int incr - value to increment (or possible decrease) nice value of a calling process by
	 *
	 * @return int - new nice value
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	int nice(int incr) noexcept(false) ;

	/**
	 * @brief pathconf - gets configurable pathname variables
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/pathconf.html for more details
	 *
	 * @param const char* path - pathname to file / directory
	 * @param int name - the configurable limit / option to get
	 *
	 * @return long - the variable value / limit
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	long pathconf(const char* path, int name) noexcept(false) ;

	/**
	 * @brief pause - suspend the thread until a signal is received
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/pause.html for more details
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void pause() noexcept(false) ;

	/**
	 * @brief pipe - create an interprocess channel
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/pipe.html for more details
	 *
	 * @param int fildes[2] - array capable of storing 2+ integers to stash created file descriptors each for a respective end of the pipe
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void pipe(int fildes[2]) noexcept(false) ;

	/**
	 * @brief pread - read from a seekable file from a given position in the file without changing the file pointer
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/pread.html for more details
	 *
	 * @param int fildes - open file descriptor to read from
	 * @param void* buf - buffer to stash data
	 * @param size_t nbyte - number of bytes to read
	 * @param off_t offset - position to read from
	 *
	 * @return ssize_t - number of bytes read
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t pread(int fildes, void* buf, size_t nbyte, off_t offset) noexcept(false) ;

	/**
	 * @brief pwrite - writes from a seekable file from a given position in the file without changing the file pointer
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/pwrite.html for more details
	 *
	 * @param int fildes - open file descriptor to read from
	 * @param const void* buf - buffer of supplied data
	 * @param size_t nbyte - number of bytes to write
	 * @param off_t offset - position to write from
	 *
	 * @return ssize_t - number of bytes written
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t pwrite(int fildes, const void* buf, size_t nbyte, off_t offset) noexcept(false) ;

	/**
	 * @brief read - read from a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/read.html for more details
	 *
	 * @param int fildes - open file descriptor to read from
	 * @param void* buf - buffer to stash data
	 * @param size_t nbyte - number of bytes to read
	 *
	 * @return ssize_t - number of bytes read
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t read(int fildes, void* buf, size_t nbyte) noexcept(false) ;

	/**
	 * @brief readlink - reads the contents of a symbolic link
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/readlink.html for more details
	 *
	 * @param const char* path - buffer containing path to symbolic link
	 * @param char* buf - buffer to stash data
	 * @param size_t bufsize - number of bytes to read
	 *
	 * @return ssize_t - number of bytes read
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t readlink(const char* path, char* buf, size_t bufsize) noexcept(false) ;

	/**
	 * @brief rmdir - removes a directory
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/rmdir.html for more details
	 *
	 * @param const char* path - buffer containing path to directory
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void rmdir(const char* path) noexcept(false) ;

	/**
	 * @brief setegid - set the effective group ID for calling process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setegid.html for more details
	 *
	 * @param gid_t gid - effective group ID to set
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void setegid(gid_t gid) noexcept(false) ;

	/**
	 * @brief seteuid - set the effective user ID for calling process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/seteuid.html for more details
	 *
	 * @param uid_t uid - effective user ID to set
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void seteuid(uid_t uid) noexcept(false) ;

	/**
	 * @brief setgid - set group ID of calling process
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setgid.html for more details
	 *
	 * @param gid_t gid - group ID to set
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void setgid(gid_t gid) noexcept(false) ;

	/**
	 * @brief setpgid - set process group ID for job control
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setpgid.html for more details
	 *
	 * @param pid_t pid - process ID which we want to set group ID of
	 * @param pid_t pgid - intended process group ID
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void setpgid(pid_t pid, pid_t pgid) noexcept(false) ;

	/**
	 * @brief setpgrd - set process group ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setpgrd.html for more details
	 *
	 * @return pid_t - process group ID
	 */
	pid_t setpgrp() noexcept ;

	/**
	 * @brief setregid - sets the real and effective group IDs
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setregid.html for more details
	 *
	 * @param gid_t rgid - new real group ID
	 * @param gid_t egid - new effective group ID
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void setregid(gid_t rgid, gid_t egid) noexcept(false) ;

	/**
	 * @brief setregid - sets the real and effective user IDs
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setreuid.html for more details
	 *
	 * @param gid_t ruid - new real new ID
	 * @param gid_t euid - new effective new ID
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void setreuid(uid_t ruid, uid_t euid) noexcept(false) ;

	/**
	 * @brief setsid - create session and set process group ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setsid.html for more details
	 *
	 * @return pid_t - new process group ID
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	pid_t setsid() noexcept(false) ;

	/**
	 * @brief setuid - create user ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/setuid.html for more details
	 *
	 * @param uid_t uid - user ID to set
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void setuid(uid_t uid) noexcept(false) ;

	/**
	 * @brief sleep - suspend execution for an interval of time
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sleep.html for more details
	 *
	 * @param unsigned seconds - number of seconds to sleep
	 *
	 * @return unsigned - the number of seconds provided not slept
	 */
	unsigned sleep(unsigned seconds) noexcept ;

	/**
	 * @brief swab - swap bytes
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/swab.html for more details
	 *
	 * @param const void* src - supply of data
	 * @param void* dest - where data is stashed
	 * @param ssize_t nbytes - number of bytes
	 */
	void swab(const void* src, void* dest, ssize_t nbytes) noexcept ;

	/**
	 * @brief symlink - makes a symbolic link
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/symlink.html for more details
	 *
	 * @param const char* path1 - path to original file
	 * @param const char* path2 - path to created symlink
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void symlink(const char* path1, const char* path2) noexcept(false) ;

	/**
	 * @brief sync - schedules file system updates
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sync.html for more details
	 */
	void sync() noexcept ;

	/**
	 * @brief sysconf - get configurable system variables
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/sysconf.html for more details
	 *
	 * @param int name - system variable to be queried
	 *
	 * @return long - value of system limit / option
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	long sysconf(int name) noexcept(false) ;

	/**
	 * @brief tcgetpgrp - get the foreground process group ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/tcgetpgrp.html for more details
	 *
	 * @param int fildes - file descriptor associated with terminal
	 *
	 * @return pid_t - process group ID of foreground process group associated with the terminal
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	pid_t tcgetpgrp(int fildes) noexcept(false) ;

	/**
	 * @brief tcsetpgrp - set the foreground process group ID
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/tcsetpgrp.html for more details
	 *
	 * @param int fildes - file descriptor associated with terminal
	 * @param pid_t pgid_id - process group ID of foreground process group to be associated with the terminal
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void tcsetpgrp(int fildes, pid_t pgid_id) noexcept(false) ;

	/**
	 * @brief truncate - truncate a file to a specified length
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/truncate.html for more details
	 *
	 * @param const char* path - path to file
	 * @param off_t length - length-to-be of file
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void truncate(const char* path, off_t length) noexcept(false) ;

	/**
	 * @brief ttyname - find the pathname of a terminal
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/ttyname.html for more details
	 *
	 * @param int fildes - file descriptor associated with terminal
	 *
	 * @return char* - pathname of the terminal
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	char* ttyname(int fildes) noexcept(false) ;

	/**
	 * @brief ttyname_r - find the pathname of a terminal
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/ttyname_r.html for more details
	 *
	 * @param int fildes - file descriptor associated with terminal
	 * @param char* name - buffer to stash terminal pathname in
	 * @param size_t namesize - size of buffer argument `name`
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void ttyname_r(int fildes, char* name, size_t namesize) noexcept(false) ;

	/**
	 * @brief ualarm - set the interval timer
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/ualarm.html for more details
	 *
	 * @param useconds_t useconds - time in microseconds to elapse before SIGALRM is generated
	 * @param useconds_t interval - time in microseconds to elapse, if non-zero, to regenerate SIGARM
	 *
	 * @return useconds_t - number of microseconds remaining from previous ualarm call
	 */
	useconds_t ualarm(useconds_t useconds, useconds_t interval) noexcept ;

	/**
	 * @brief unlink - remove a directory entry
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/unlink.html for more details
	 *
	 * @param const char* path - pathname to existing file
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void unlink(const char* path) noexcept(false) ;

	/**
	 * @brief usleep - suspend execution for an interval of time
	 * See https://pubs.opengroup.org/onlinepubs/009696899/functions/usleep.html for more details
	 *
	 * @param useconds_t useconds - number of microseconds to sleep
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	void usleep(useconds_t useconds) noexcept(false) ;

	/**
	 * @brief vfork - creates a new process whilst sharing virtual memory
	 * See https://pubs.opengroup.org/onlinepubs/009696899/functions/vfork.html for more details
	 *
	 * @return pid_t - process ID of the created child process
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	pid_t vfork() noexcept(false) ;

	/**
	 * @brief write - writes from a file
	 * See https://pubs.opengroup.org/onlinepubs/009695399/functions/write.html for more details
	 *
	 * @param int fildes - open file descriptor to read from
	 * @param const void* buf - buffer of supplied data
	 * @param size_t nbyte - number of bytes to write
	 *
	 * @return ssize_t - number of bytes written
	 *
	 * @throws posicxx::Error - exception thrown upon error
	 */
	ssize_t write(int fildes, const void* buf, size_t nbyte) noexcept(false) ;

}

#endif // #ifndef UNISTD_HH
