# CMakeList.txt : CMake project for 1234, include source and define
# project specific logic here.

add_executable (1234 "1234.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1234 PROPERTY CXX_STANDARD 20)
endif()
