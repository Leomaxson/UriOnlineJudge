# CMakeList.txt : CMake project for 1607, include source and define
# project specific logic here.

add_executable (1607 "1607.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1607 PROPERTY CXX_STANDARD 20)
endif()
