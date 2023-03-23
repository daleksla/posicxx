### GNU Makefile build file

# Compiler Settings

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

# Project-specific settings

INCLUDES = -I include/
OTHER_FLAGS ?= -g

all: error_handler semaphore
	@echo "\033[0;35m""Linking objects into archive file" "\033[0m"
	ar -crs lib/posicxx.a lib/*.o # link all object files here

.PHONY: all

error_handler:
	@echo "\033[0;35m""Building error handler" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) $(INCLUDES) -c src/error.cc -o lib/error.o

semaphore: error_handler
	@echo "\033[0;35m""Building semaphore object" "\033[0m"
	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) $(INCLUDES) -c src/semaphore.cc -o lib/semaphore.o
#	cc $(STD) $(WARN_FLAGS) $(OTHER_FLAGS) $(INCLUDES) -c src/semaphore_interface.cc -o lib/semaphore_interface.o

clean:
	@echo "\033[0;35m""Purging library and objects" "\033[0m"
	rm lib/* || true

