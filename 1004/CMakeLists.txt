# CMakeList.txt : CMake project for 1004, include source and define
# project specific logic here.

add_executable (1004 "1004.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1004 PROPERTY CXX_STANDARD 20)
endif()
