# CMakeList.txt : CMake project for 1012, include source and define
# project specific logic here.

add_executable (1012 "1012.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1012 PROPERTY CXX_STANDARD 20)
endif()
