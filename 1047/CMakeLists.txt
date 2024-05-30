# CMakeList.txt : CMake project for 1047, include source and define
# project specific logic here.

add_executable (1047 "1047.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1047 PROPERTY CXX_STANDARD 20)
endif()
