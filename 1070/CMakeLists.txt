# CMakeList.txt : CMake project for 1070, include source and define
# project specific logic here.

add_executable (1070 "1070.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1070 PROPERTY CXX_STANDARD 20)
endif()
