# CMakeList.txt : CMake project for 1246, include source and define
# project specific logic here.

add_executable (1246 "1246.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1246 PROPERTY CXX_STANDARD 20)
endif()
