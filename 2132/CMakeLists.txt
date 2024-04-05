# CMakeList.txt : CMake project for 2132, include source and define
# project specific logic here.

add_executable (2132 "2132.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2132 PROPERTY CXX_STANDARD 20)
endif()
