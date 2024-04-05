# CMakeList.txt : CMake project for 2588, include source and define
# project specific logic here.

add_executable (2588 "2588.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2588 PROPERTY CXX_STANDARD 20)
endif()
