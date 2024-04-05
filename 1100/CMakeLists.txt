# CMakeList.txt : CMake project for 1100, include source and define
# project specific logic here.

add_executable (1100 "1100.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1100 PROPERTY CXX_STANDARD 20)
endif()
