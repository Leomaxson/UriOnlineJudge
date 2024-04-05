# CMakeList.txt : CMake project for 1278, include source and define
# project specific logic here.

add_executable (1278 "1278.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1278 PROPERTY CXX_STANDARD 20)
endif()
