# CMakeList.txt : CMake project for 1002, include source and define
# project specific logic here.

add_executable (1002 "1002.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1002 PROPERTY CXX_STANDARD 20)
endif()
