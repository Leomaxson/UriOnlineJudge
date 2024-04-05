# CMakeList.txt : CMake project for 1110, include source and define
# project specific logic here.

add_executable (1110 "1110.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1110 PROPERTY CXX_STANDARD 20)
endif()
