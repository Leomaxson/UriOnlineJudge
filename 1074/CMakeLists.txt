# CMakeList.txt : CMake project for 1074, include source and define
# project specific logic here.

add_executable (1074 "1074.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1074 PROPERTY CXX_STANDARD 20)
endif()
