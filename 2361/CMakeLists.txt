# CMakeList.txt : CMake project for 2361, include source and define
# project specific logic here.

add_executable (2361 "2361.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2361 PROPERTY CXX_STANDARD 20)
endif()
