# CMakeList.txt : CMake project for 1157, include source and define
# project specific logic here.

add_executable (1157 "1157.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1157 PROPERTY CXX_STANDARD 20)
endif()
