# CMakeList.txt : CMake project for 1621, include source and define
# project specific logic here.

add_executable (1621 "1621.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1621 PROPERTY CXX_STANDARD 20)
endif()
