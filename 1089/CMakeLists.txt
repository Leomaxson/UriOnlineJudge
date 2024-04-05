# CMakeList.txt : CMake project for 1089, include source and define
# project specific logic here.

add_executable (1089 "1089.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1089 PROPERTY CXX_STANDARD 20)
endif()
