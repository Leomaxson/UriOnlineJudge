# CMakeList.txt : CMake project for 1790, include source and define
# project specific logic here.

add_executable (1790 "1790.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1790 PROPERTY CXX_STANDARD 20)
endif()
