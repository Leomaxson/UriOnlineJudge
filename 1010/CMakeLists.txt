# CMakeList.txt : CMake project for 1010, include source and define
# project specific logic here.

add_executable (1010 "1010.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1010 PROPERTY CXX_STANDARD 20)
endif()
