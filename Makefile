### GNU Makefile build file

# Prebuild Configuration

## Compiler Settings

STD = --std=c++11

WARN_FLAGS = -Werror \
-Wpedantic \
-Wall \
-Wextra \
-Wcast-align \
-Wcast-qual \
-Wfloat-equal \
-Wformat=2 \
-Wlogical-op \
-Wpointer-arith \
-Wundef \
-Wno-pointer-compare \
-Wredundant-decls \
-Wsequence-point \
-Wshadow \
-Wswitch \
-Wundef \
-Wunreachable-code \
-Wunused-but-set-parameter \
-Wwrite-strings

## Project-specific settings

INCLUDE_DIR = ./include/

SRC_DIR = ./src

DEST_DIR = ./lib

OTHER_FLAGS ?= -g

# Build

## Meta builders

all: error_handler aio arpa/inet assert complex ctype dirent dlfcn fcntl fenv fmtmsg fnmatch ftw glob grp iconv inttypes langinfo libgen locale math monetary mqueue ndbm net/if netdb netinet/in netinet/tcp nl_types poll pthread pwd regex sched search semaphore setjmp signal spawn stdarg stdio stdlib string strings stropts sys/ipc sys/mman sys/msg sys/resource sys/select sys/sem sys/shm sys/socket sys/stat sys/statvfs sys/time sys/timeb sys/times sys/uio sys/un sys/utsname sys/wait syslog termios tgmath time trace ucontext ulimit unistd utime utmpx wchar wctype wordexp
	@echo "\033[0;35m""Linking objects into archive file" "\033[0m"
	ar -crs $(DEST_DIR)/posicxx.a $(DEST_DIR)/*.o # link all object files here

.PHONY: all

clean:
	@echo "\033[0;35m""Purging lib/" "\033[0m"
	rm lib/* || true

## Actual build

error_handler:
	@echo "\033[0;35m""Building error handler object" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/error.cc -o $(DEST)/error.o

aio:

arpa/inet:
	

assert:
	@echo "\033[0;35m""Building assert objects" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/assert.cc -o $(DEST)/assert.o

complex:
	

ctype:
	

dirent:
	

dlfcn:
	

fcntl:
	

fenv:
	

fmtmsg:
	

fnmatch:
	

ftw:
	

glob:
	

grp:
	

iconv:
	

inttypes:
	

langinfo:
	

libgen:
	

locale:
	

math:
	

monetary:
	

mqueue:
	

ndbm:
	

net/if:
	

netdb:
	

netinet/in:
	

netinet/tcp:
	

nl_types:
	

poll:

pthread:
	

pwd:
	

regex:
	

sched:
	

search:
	

semaphore: error_handler
	@echo "\033[0;35m""Building semaphore objects" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/semaphore_core.cc -o $(DEST)/semaphore_core.o
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) $(DEST)/semaphore_core.o -c $(SRC_DIR)/semaphore_interface.cc -o $(DEST)/semaphore_interface.o

setjmp:
	

signal:
	

spawn:
	

stdarg:
	

stdio:
	

stdlib:
	

string:
	

strings:
	

stropts:
	

sys/ipc:
	

sys/mman:
	

sys/msg:
	

sys/resource:
	

sys/select:
	

sys/sem:
	

sys/shm:
	

sys/socket:
	

sys/stat:
	

sys/statvfs:
	

sys/time:
	

sys/timeb:
	

sys/times:
	

sys/uio:
	

sys/un:
	

sys/utsname:
	

sys/wait:
	

syslog:
	

termios:
	

tgmath:
	

time:
	

trace:
	

ucontext:
	

ulimit:
	

unistd:
	

utime:
	

utmpx:
	

wchar:
	

wctype:
	

wordexp:
	
