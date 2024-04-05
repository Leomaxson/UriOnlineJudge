# CMakeList.txt : CMake project for 1238, include source and define
# project specific logic here.

add_executable (1238 "1238.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1238 PROPERTY CXX_STANDARD 20)
endif()
