# CMakeList.txt : CMake project for 2356, include source and define
# project specific logic here.

add_executable (2356 "2356.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2356 PROPERTY CXX_STANDARD 20)
endif()
