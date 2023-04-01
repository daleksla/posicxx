#include <cstdarg>

#include "error.hh"

#include "unistd.hh"

/**
 * @brief unistd.cc - file serves as CXX definitions of POSIX miscellaneous functionality, containing the minimal wrapper, fancy interface and resource manager
 * For internal use only
 */

//posicxx::Fildes::Fildes(const int fd) noexcept(false)
//{
//	this->_fd = fd ;
//}
//
//posicxx::Fildes::Fildes(const char* pathname, int flags) noexcept(false) 
//{
//	this->_fd = posicxx::open(pathname, flags) ;
//}
//
//posicxx::Fildes::Fildes(const char* pathname, int flags, mode_t mode) noexcept(false) 
//{
//	this->_fd = posicxx::open(pathname, flags, mode) ;
//}
//
//posicxx::Fildes::Fildes(const posicxx::Fildes& fd) noexcept(false) 
//{
//	this->_fd = posicxx::dup(fd._fd) ;
//}
//
//posicxx::Fildes& posicxx::Fildes::operator=(const posicxx::Fildes& fd) noexcept(false) 
//{
//	this->_fd = posicxx::dup(fd._fd) ;
//	return *this;
//}
//
//posicxx::Fildes::Fildes(posicxx::Fildes&& fd) noexcept(false)
//{
//	this->_fd = fd._fd ;
//	fd._fd = -1 ;
//}
//
//posicxx::Fildes& posicxx::Fildes::operator=(posicxx::Fildes&& fd) noexcept(false) 
//{
//	this->_fd = fd._fd ;
//	fd._fd = -1 ;
//	return *this;
//}
//
//posicxx::Fildes::~Fildes() noexcept
//{
//	try {
//		posicxx::close(this->_fd) ;
//	}
//	catch(const posicxx::Error& err)
//	{}
//}
//
//int posicxx::Fildes::operator()() const noexcept 
//{
//	return this->_fd ;
//}

void posicxx::access(const char* path, int amode)noexcept(false)
{
	if(::access(path, amode) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

unsigned posicxx::alarm(unsigned seconds) noexcept
{
	return ::alarm(seconds) ;
}

void posicxx::chdir(const char* path) noexcept(false)
{
	if(::chdir(path) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::chown(const char* path, uid_t owner, gid_t group) noexcept(false)
{
	if(::chown(path, owner, group) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::close(int fildes) noexcept(false)
{
	if(::close(fildes) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

size_t posicxx::confstr(int name, char* buf, size_t len) noexcept(false)
{
	errno = POSICXX_UNDEFINED_ERROR ;
	const size_t res = ::confstr(name, buf, len) ;

	if(res == 0) // if error & errno was set
	{
		throw posicxx::Error(errno == POSICXX_UNDEFINED_ERROR ? POSICXX_UNDEFINED_ERROR : errno) ;
	}

	return res ;
}

void posicxx::crypt(const char* key, const char* salt) noexcept(false)
{
	if(::crypt(key, salt) == NULL)
	{
		throw posicxx::Error(errno) ;
	}
}

char* posicxx::ctermid(char* s) noexcept(false)
{
	char* res = ::ctermid(s) ;

	if(*res == '\0')
	{
		throw posicxx::Error(POSICXX_UNDEFINED_ERROR) ;
	}

	return res ;
}

int posicxx::dup(int fildes) noexcept(false)
{
	int fd = ::dup(fildes) ;

	if(fd < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return fd ;
}

int posicxx::dup2(int fildes, int fildes2) noexcept(false)
{
	int fd = ::dup2(fildes, fildes2) ;

	if(fd < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return fd ;
}

void posicxx::encrypt(char block[64], int edflag) noexcept(false)
{
	errno = POSICXX_UNDEFINED_ERROR ;
	::encrypt(block, edflag) ;

	if(errno != 0) // if errno was set
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::execl(const char* path, const char* arg0, ...) noexcept(false)
{
	size_t argc ;

	va_list ap ;
	va_start(ap, arg0) ;
	for(argc = 1 ; va_arg(ap, const char*) ; ++argc)
	{
		if(argc == SIZE_MAX)
		{
			va_end(ap) ;
			errno = E2BIG ; // we could just throw E2BIG directly BUT I'd rather errno be set
			throw posicxx::Error(errno) ;
		}
	}
	va_end(ap) ;

	char* argv[argc + 1] ; // 1 (initial arg0) + argc (remaining args - this includes NULL)
	argv[0] = const_cast<char*>(arg0) ;
	va_start(ap, arg0) ;
	for(size_t i = 1 ; i <= argc ; ++i)
	{
		argv[i] = va_arg(ap, char*) ;
	}
	va_end(ap) ;

	posicxx::execv(path, argv) ;
}

void posicxx::execle(const char* path, const char* arg0, ...) noexcept(false)
{
	size_t argc ;

	va_list ap ;
	va_start(ap, arg0) ;
	for(argc = 1 ; va_arg(ap, const char*) == NULL ; ++argc)
	{
		if(argc == SIZE_MAX)
		{
			va_end(ap) ;
			errno = E2BIG ; // we could just throw E2BIG directly BUT I'd rather errno be set
			throw posicxx::Error(errno) ;
		}
	}
	va_end(ap) ;

	char* argv[argc + 1] ; // 1 (initial arg0) + argc (remaining args - this includes NULL)
	va_start(ap, arg0) ;
	argv[0] = const_cast<char*>(arg0) ;
	for(size_t i = 1 ; i <= argc ; ++i)
	{
		argv[i] = va_arg(ap, char*) ;
	}
	char** const envp = va_arg(ap, char**) ;
	va_end(ap) ;

	posicxx::execve(path, argv, envp) ;
}

void posicxx::execlp(const char* file, const char* arg0, ...) noexcept(false)
{
	size_t argc ;

	va_list ap ;
	va_start(ap, arg0) ;
	for(argc = 1 ; va_arg(ap, const char*) ; ++argc)
	{
		if(argc == SIZE_MAX)
		{
			va_end(ap) ;
			errno = E2BIG ; // we could just throw E2BIG directly BUT I'd rather errno be set
			throw posicxx::Error(errno) ;
		}
	}
	va_end(ap) ;

	char* argv[argc + 1] ; // 1 (initial arg0) + argc (remaining args - this includes NULL)
	va_start(ap, arg0) ;
	argv[0] = const_cast<char*>(arg0) ;
	for(size_t i = 1 ; i <= argc ; ++i)
	{
		argv[i] = va_arg(ap, char*) ;
	}
	va_end(ap) ;

	posicxx::execvp(file, argv) ;
}

void posicxx::execv(const char* path, char* const argv[]) noexcept(false)
{
	posicxx::execve(path, argv, environ) ;
}

void posicxx::execve(const char* path, char* const argv[], char* const envp[]) noexcept(false)
{
	if(::execve(path, argv, envp) == -1)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::execvp(const char* file, char* const argv[]) noexcept(false)
{
	if(::execvp(file, argv) == -1)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::_exit(int status) noexcept
{
	::exit(status) ;
}

void posicxx::fchown(int fildes, uid_t owner, gid_t group) noexcept(false)
{
	if(::fchown(fildes, owner, group) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::fchdir(int fildes) noexcept(false)
{
	if(::fchdir(fildes) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::fdatasync(int fildes) noexcept(false)
{
	if(::fdatasync(fildes) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

pid_t posicxx::fork() noexcept(false)
{
	const pid_t pid = ::fork() ;

	if(pid < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return pid ;
}

long posicxx::fpathconf(int fildes, int name) noexcept(false)
{
	errno = POSICXX_UNDEFINED_ERROR ;
	const long pathv = ::fpathconf(fildes, name) ;

	if(pathv < 0)
	{
		throw posicxx::Error(errno == POSICXX_UNDEFINED_ERROR ? POSICXX_UNDEFINED_ERROR : errno) ;
	}

	return pathv ;
}

void posicxx::fsync(int fildes) noexcept(false)
{
	if(::fsync(fildes) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::ftruncate(int fildes, off_t length) noexcept(false)
{
	if(::ftruncate(fildes, length) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::getcwd(char* buf, size_t size) noexcept(false)
{
	if(::getcwd(buf, size) == NULL)
	{
		throw posicxx::Error(errno) ;
	}
}

gid_t posicxx::getegid() noexcept
{
	return ::getegid() ;
}

uid_t posicxx::geteuid() noexcept
{
	return ::geteuid() ;
}

gid_t posicxx::getgid() noexcept
{
	return ::getgid() ;
}

int posicxx::getgroups(int gidsetsize, gid_t grouplist[]) noexcept(false)
{
	int sup_groupids = ::getgroups(gidsetsize, grouplist) ;

	if(sup_groupids < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return sup_groupids ;
}

long posicxx::gethostid() noexcept
{
	return ::gethostid() ;
}

void posicxx::gethostname(char* name, size_t namelen) noexcept(false)
{
	if(::gethostname(name, namelen) != 0)
	{
		throw posicxx::Error(POSICXX_UNDEFINED_ERROR) ;
	}
}

char* posicxx::getlogin() noexcept(false)
{
	char* loginn = ::getlogin() ;

	if(loginn == NULL)
	{
		throw posicxx::Error(POSICXX_UNDEFINED_ERROR) ;
	}

	return loginn ;
}

void posicxx::getlogin_r(char* name, size_t namesize)noexcept(false)
{
	if(::getlogin_r(name, namesize) != 0)
	{
		throw posicxx::Error(POSICXX_UNDEFINED_ERROR) ;
	}
}

int posicxx::getopt(int argc, char* const argv[], const char* optstring) noexcept
{
	return ::getopt(argc, argv, optstring) ;
}

pid_t posicxx::getpgid(pid_t pid) noexcept(false)
{
	const pid_t rpid = ::getpgid(pid) ;

	if(rpid == static_cast<pid_t>(-1))
	{
		throw posicxx::Error(errno) ;
	}

	return rpid ;
}

pid_t posicxx::getpgrp() noexcept
{
	return ::getpgrp() ;
}

pid_t posicxx::getpid() noexcept
{
	return ::getpid() ;
}

pid_t posicxx::getppid() noexcept
{
	return ::getppid() ;
}

pid_t posicxx::getsid(pid_t pid) noexcept(false)
{
	const pid_t rpid = ::getsid(pid) ;

	if(rpid == static_cast<pid_t>(-1))
	{
		throw posicxx::Error(errno) ;
	}

	return rpid ;
}

uid_t posicxx::getuid() noexcept
{
	return ::getuid() ;
}

void posicxx::getwd(char* path_name) noexcept(false)
{
	if(::getwd(path_name) == NULL)
	{
		throw posicxx::Error(POSICXX_UNDEFINED_ERROR) ;
	}
}

int posicxx::isatty(int fildes) noexcept(false)
{
	int result = ::isatty(fildes) ;

	if(result == 0 && errno != ENOTTY)
	{
		throw posicxx::Error(errno) ;
	}

	return result ;
}

void posicxx::lchown(const char* path, uid_t owner, gid_t group) noexcept(false)
{
	if(::lchown(path, owner, group) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::link(const char* path1, const char* path2) noexcept(false)
{
	if(::link(path1, path2) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::lockf(int fildes, int function, off_t size) noexcept(false)
{
	if(::lockf(fildes, function, size) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

off_t posicxx::lseek(int fildes, off_t offset, int whence) noexcept(false)
{
	const off_t sought = ::lseek(fildes, offset, whence) ;

	if(sought == static_cast<off_t>(-1))
	{
		throw posicxx::Error(sought) ;
	}

	return sought ;
}

int posicxx::nice(int incr) noexcept(false)
{
	const int nnice = ::nice(incr) ;

	if(nnice == -1)
	{
		throw posicxx::Error(errno) ;
	}

	return nnice ;
}

long posicxx::pathconf(const char* path, int name) noexcept(false)
{
	errno = POSICXX_UNDEFINED_ERROR ;
	const long pathv = ::pathconf(path, name) ;

	if(pathv < 0)
	{
		throw posicxx::Error(errno == POSICXX_UNDEFINED_ERROR ? POSICXX_UNDEFINED_ERROR : errno) ;
	}

	return pathv ;
}

void posicxx::pause() noexcept(false)
{
	if(::pause() == -1)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::pipe(int fildes[2]) noexcept(false)
{
	if(::pipe(fildes) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

ssize_t posicxx::pread(int fildes, void* buf, size_t nbyte, off_t offset) noexcept(false)
{
	ssize_t rread = ::pread(fildes, buf, nbyte, offset) ;

	if(rread < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return rread ;
}

ssize_t posicxx::pwrite(int fildes, const void* buf, size_t nbyte, off_t offset) noexcept(false)
{
	ssize_t rwrite = ::pwrite(fildes, buf, nbyte, offset) ;

	if(rwrite < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return rwrite ;
}

ssize_t posicxx::read(int fildes, void* buf, size_t nbyte) noexcept(false)
{
	ssize_t rread = ::read(fildes, buf, nbyte) ;

	if(rread < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return rread ;
}

ssize_t posicxx::readlink(const char* path, char* buf, size_t bufsize) noexcept(false)
{
	ssize_t rread = ::readlink(path, buf, bufsize) ;

	if(rread < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return rread ;
}

void posicxx::rmdir(const char* path) noexcept(false)
{
	if(::rmdir(path) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::setegid(gid_t gid) noexcept(false)
{
	if(::setegid(gid) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::seteuid(uid_t uid) noexcept(false)
{
	if(::seteuid(uid) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::setgid(gid_t gid) noexcept(false)
{
	if(::setegid(gid) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::setpgid(pid_t pid, pid_t pgid) noexcept(false)
{
	if(::setpgid(pid, pgid) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

pid_t posicxx::setpgrp() noexcept
{
	return ::setpgrp() ;
}

void posicxx::setregid(gid_t rgid, gid_t egid) noexcept(false)
{
	if(::setregid(rgid, egid) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::setreuid(uid_t ruid, uid_t euid) noexcept(false)
{
	if(::setreuid(ruid, euid) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

pid_t posicxx::setsid() noexcept(false)
{
	const pid_t rsid = ::setsid() ;

	if(rsid == static_cast<pid_t>(-1))
	{
		throw posicxx::Error(errno) ;
	}

	return rsid ;
}

void posicxx::setuid(uid_t uid) noexcept(false)
{
	if(::setuid(uid) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

unsigned posicxx::sleep(unsigned seconds) noexcept
{
	return ::sleep(seconds) ;
}

void posicxx::swab(const void* src, void* dest, ssize_t nbytes) noexcept
{
	::swab(src, dest, nbytes) ;
}

void posicxx::symlink(const char* path1, const char* path2) noexcept(false)
{
	if(::symlink(path1, path2) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::sync() noexcept
{
	::sync() ;
}

long posicxx::sysconf(int name) noexcept(false)
{
	errno = POSICXX_UNDEFINED_ERROR ;
	const long rsconf = ::sysconf(name) ;

	if(rsconf == -1)
	{
		throw posicxx::Error(errno == POSICXX_UNDEFINED_ERROR ? POSICXX_UNDEFINED_ERROR : errno) ;
	}

	return rsconf ;
}

pid_t posicxx::tcgetpgrp(int fildes) noexcept(false)
{
	const pid_t rtcpgrp = ::tcgetpgrp(fildes) ;

	if(rtcpgrp < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return rtcpgrp ;
}

void posicxx::tcsetpgrp(int fildes, pid_t pgid_id) noexcept(false)
{
	if(::tcsetpgrp(fildes, pgid_id) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::truncate(const char* path, off_t length) noexcept(false)
{
	if(::truncate(path, length) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

char* posicxx::ttyname(int fildes) noexcept(false)
{
	char* rttyname = ::ttyname(fildes) ;

	if(rttyname != 0)
	{
		throw posicxx::Error(errno) ;
	}

	return rttyname ;
}

void posicxx::ttyname_r(int fildes, char* name, size_t namesize) noexcept(false)
{
	if(::ttyname_r(fildes, name, namesize) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

useconds_t posicxx::ualarm(useconds_t useconds, useconds_t interval) noexcept
{
	return ::ualarm(useconds, interval) ;
}

void posicxx::unlink(const char* path) noexcept(false)
{
	if(::unlink(path) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

void posicxx::usleep(useconds_t useconds) noexcept(false)
{
	if(::usleep(useconds) != 0)
	{
		throw posicxx::Error(errno) ;
	}
}

pid_t posicxx::vfork() noexcept(false)
{
	const pid_t pid = ::vfork() ;

	if(pid < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return pid ;
}

ssize_t posicxx::write(int fildes, const void* buf, size_t nbyte) noexcept(false)
{
	ssize_t rwrite = ::write(fildes, buf, nbyte) ;

	if(rwrite < 0)
	{
		throw posicxx::Error(errno) ;
	}

	return rwrite ;
}
