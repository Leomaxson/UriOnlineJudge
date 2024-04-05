# CMakeList.txt : CMake project for 1364, include source and define
# project specific logic here.

add_executable (1364 "1364.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1364 PROPERTY CXX_STANDARD 20)
endif()
