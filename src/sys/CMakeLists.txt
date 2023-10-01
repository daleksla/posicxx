# src/sys/CMakeLists.txt

add_library(socket socket.cc)
set_required_build_settings_for_GCC8(socket)
