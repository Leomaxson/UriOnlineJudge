# CMakeList.txt : CMake project for 1065, include source and define
# project specific logic here.

add_executable (1065 "1065.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1065 PROPERTY CXX_STANDARD 20)
endif()
