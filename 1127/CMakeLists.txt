# CMakeList.txt : CMake project for 1127, include source and define
# project specific logic here.

add_executable (1127 "1127.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1127 PROPERTY CXX_STANDARD 20)
endif()
