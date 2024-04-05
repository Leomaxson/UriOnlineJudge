# CMakeList.txt : CMake project for 1008, include source and define
# project specific logic here.

add_executable (1008 "1008.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1008 PROPERTY CXX_STANDARD 20)
endif()
