# CMakeList.txt : CMake project for 1471, include source and define
# project specific logic here.

add_executable (1471 "1471.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1471 PROPERTY CXX_STANDARD 20)
endif()
