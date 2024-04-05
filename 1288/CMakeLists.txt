# CMakeList.txt : CMake project for 1288, include source and define
# project specific logic here.

add_executable (1288 "1288.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1288 PROPERTY CXX_STANDARD 20)
endif()
