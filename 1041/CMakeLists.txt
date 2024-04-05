# CMakeList.txt : CMake project for 1041, include source and define
# project specific logic here.

add_executable (1041 "1041.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1041 PROPERTY CXX_STANDARD 20)
endif()
