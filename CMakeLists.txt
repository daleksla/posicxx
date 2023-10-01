cmake_minimum_required(VERSION 3.20)

### Project name and a few useful settings. Other commands can pick up the results ###
project(
	benchmarks
	DESCRIPTION "Suite of tests to benchmark behaviours of parallel programming frameworks (compared also to a serial implementation)."
	LANGUAGES CXX
	VERSION 1.0
)

### Set where CMake will output files ###
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

### Configure relevant toolchains used to compile ###
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

function( set_required_build_settings_for_GCC8 )
	# Always link with libstdc++fs.a when using GCC 8.
	# Note: This command makes sure that this option comes pretty late on the cmdline.
	link_libraries("$<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_LESS:$<CXX_COMPILER_VERSION>,9.0>>:-lstdc++fs>")
endfunction()

set_required_build_settings_for_GCC8()

### Now actually compile ###
## Add general compile options and flags ##
add_compile_options(
	-Werror
	-Wpedantic
	-Wall
	-Wextra
	-Wcast-align
	-Wcast-qual
	-Wfloat-equal
	-Wformat=2
	-Wlogical-op
	-Wpointer-arith
	-Wundef
	-Wno-pointer-compare
	-Wredundant-decls
	-Wsequence-point
	-Wshadow
	-Wswitch
	-Wundef
	-Wunreachable-code
	-Wunused-but-set-parameter
	-Wwrite-strings
	-Wno-deprecated-declarations
	-fexceptions
)

include_directories(
	include/
	src/
	src/*/
)

## Compile tasks ##
add_subdirectory(src/)
add_subdirectory(src/arpa)
add_subdirectory(src/net)
add_subdirectory(src/netinet)
add_subdirectory(src/sys)
