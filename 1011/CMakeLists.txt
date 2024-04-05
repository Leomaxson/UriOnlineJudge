# CMakeList.txt : CMake project for 1011, include source and define
# project specific logic here.

add_executable (1011 "1011.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1011 PROPERTY CXX_STANDARD 20)
endif()
