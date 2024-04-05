# CMakeList.txt : CMake project for 2355, include source and define
# project specific logic here.

add_executable (2355 "2355.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2355 PROPERTY CXX_STANDARD 20)
endif()
