# CMakeList.txt : CMake project for 1271, include source and define
# project specific logic here.

add_executable (1271 "1271.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1271 PROPERTY CXX_STANDARD 20)
endif()
