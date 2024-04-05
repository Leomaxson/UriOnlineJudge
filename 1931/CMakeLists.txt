# CMakeList.txt : CMake project for 1931, include source and define
# project specific logic here.

add_executable (1931 "1931.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1931 PROPERTY CXX_STANDARD 20)
endif()
