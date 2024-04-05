# CMakeList.txt : CMake project for 1273, include source and define
# project specific logic here.

add_executable (1273 "1273.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1273 PROPERTY CXX_STANDARD 20)
endif()
