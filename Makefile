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

## Actual build

all: error_handler aio arpa/inet complex ctype dirent dlfcn fcntl fenv fmtmsg fnmatch ftw glob grp iconv inttypes langinfo libgen locale math monetary mqueue ndbm net/if netdb netinet/in netinet/tcp nl_types poll pthread pwd regex sched search semaphore setjmp signal spawn stdio stdlib string strings stropts sys/ipc sys/mman sys/msg sys/resource sys/select sys/sem sys/shm sys/socket sys/stat sys/statvfs sys/time sys/timeb sys/times sys/uio sys/un sys/utsname sys/wait syslog termios tgmath time trace ucontext ulimit unistd fildes utime utmpx wchar wctype wordexp
	@echo "\033[0;35m""Linking objects into archive file" "\033[0m"
	ar -crs $(DEST_DIR)/posicxx.a $(DEST_DIR)/*.o # link all object files here

error_handler:
	@echo "\033[0;35m""Building error handler object(s)" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/error.cc -o $(DEST_DIR)/error_handler.o

aio:

arpa/inet:
	

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
	@echo "\033[0;35m""Building semaphore object(s)" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/semaphore.cc -o $(DEST_DIR)/semaphore.o

setjmp:
	

signal:
	

spawn:
	

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
	

sys/socket: error_handler fildes
	@echo "\033[0;35m""Building socket object(s)" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/socket.cc -o $(DEST_DIR)/socket.o

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
	

unistd: error_handler fildes
	@echo "\033[0;35m""Building unistd object(s)" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/unistd.cc -o $(DEST_DIR)/unistd.o

fildes: error_handler
	@echo "\033[0;35m""Building fildes objects" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/fildes.cc -o $(DEST_DIR)/fildes.o

utime:
	

utmpx:
	

wchar:
	

wctype:
	

wordexp:
	

## Meta builders

.PHONY: all

clean:
	@echo "\033[0;35m""Purging lib/ contents" "\033[0m"
	@rm lib/* 2> /dev/null || true

docs:
	@echo "\033[0;35m""Building documentation/" "\033[0m"
	@doxygen .doxygen/config.txt
