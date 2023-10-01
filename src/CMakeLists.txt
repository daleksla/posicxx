# src/CMakeLists.txt

add_library(fcntl fcntl.cc)
set_required_build_settings_for_GCC8(fcntl)

add_library(semaphore semaphore.cc)
set_required_build_settings_for_GCC8(semaphore)

add_library(unistd unistd.cc)
set_required_build_settings_for_GCC8(unistd)
