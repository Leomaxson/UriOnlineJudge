# CMakeList.txt : CMake project for 1379, include source and define
# project specific logic here.

add_executable (1379 "1379.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1379 PROPERTY CXX_STANDARD 20)
endif()
