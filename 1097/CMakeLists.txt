# CMakeList.txt : CMake project for 1097, include source and define
# project specific logic here.

add_executable (1097 "1097.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1097 PROPERTY CXX_STANDARD 20)
endif()
