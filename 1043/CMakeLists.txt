# CMakeList.txt : CMake project for 1043, include source and define
# project specific logic here.

add_executable (1043 "1043.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1043 PROPERTY CXX_STANDARD 20)
endif()
