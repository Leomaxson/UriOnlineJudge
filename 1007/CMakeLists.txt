# CMakeList.txt : CMake project for 1007, include source and define
# project specific logic here.

add_executable (1007 "1007.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1007 PROPERTY CXX_STANDARD 20)
endif()
