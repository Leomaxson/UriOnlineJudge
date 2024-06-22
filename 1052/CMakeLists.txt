# CMakeList.txt : CMake project for 1052, include source and define
# project specific logic here.

add_executable (1052 "1052.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1052 PROPERTY CXX_STANDARD 20)
endif()
