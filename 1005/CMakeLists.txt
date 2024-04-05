# CMakeList.txt : CMake project for 1005, include source and define
# project specific logic here.

add_executable (1005 "1005.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1005 PROPERTY CXX_STANDARD 20)
endif()
