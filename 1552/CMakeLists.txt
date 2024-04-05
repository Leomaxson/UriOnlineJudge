# CMakeList.txt : CMake project for 1552, include source and define
# project specific logic here.

add_executable (1552 "1552.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1552 PROPERTY CXX_STANDARD 20)
endif()
