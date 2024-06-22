# CMakeList.txt : CMake project for 1040, include source and define
# project specific logic here.

add_executable (1040 "1040.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1040 PROPERTY CXX_STANDARD 20)
endif()
