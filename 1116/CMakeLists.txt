# CMakeList.txt : CMake project for 1116, include source and define
# project specific logic here.

add_executable (1116 "1116.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1116 PROPERTY CXX_STANDARD 20)
endif()
