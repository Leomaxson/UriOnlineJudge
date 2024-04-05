# CMakeList.txt : CMake project for 1001, include source and define
# project specific logic here.

add_executable (1001 "1001.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1001 PROPERTY CXX_STANDARD 20)
endif()
