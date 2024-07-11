# CMakeList.txt : CMake project for 1387, include source and define
# project specific logic here.

add_executable (1387 "1387.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1387 PROPERTY CXX_STANDARD 20)
endif()
