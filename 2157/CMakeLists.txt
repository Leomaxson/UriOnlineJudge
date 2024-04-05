# CMakeList.txt : CMake project for 2157, include source and define
# project specific logic here.

add_executable (2157 "2157.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2157 PROPERTY CXX_STANDARD 20)
endif()
