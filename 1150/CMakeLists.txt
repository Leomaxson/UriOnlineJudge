# CMakeList.txt : CMake project for 1150, include source and define
# project specific logic here.

add_executable (1150 "1150.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1150 PROPERTY CXX_STANDARD 20)
endif()
