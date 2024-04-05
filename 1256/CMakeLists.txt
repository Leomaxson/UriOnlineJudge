# CMakeList.txt : CMake project for 1256, include source and define
# project specific logic here.

add_executable (1256 "1256.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1256 PROPERTY CXX_STANDARD 20)
endif()
