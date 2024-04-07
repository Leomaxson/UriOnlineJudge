# CMakeList.txt : CMake project for 1117, include source and define
# project specific logic here.

add_executable (1117 "1117.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1117 PROPERTY CXX_STANDARD 20)
endif()
