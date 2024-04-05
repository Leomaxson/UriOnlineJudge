# CMakeList.txt : CMake project for 1006, include source and define
# project specific logic here.

add_executable (1006 "1006.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1006 PROPERTY CXX_STANDARD 20)
endif()
