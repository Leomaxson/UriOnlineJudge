# CMakeList.txt : CMake project for 1228, include source and define
# project specific logic here.

add_executable (1228 "1228.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1228 PROPERTY CXX_STANDARD 20)
endif()
