# CMakeList.txt : CMake project for 1188, include source and define
# project specific logic here.

add_executable (1188 "1188.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1188 PROPERTY CXX_STANDARD 20)
endif()
