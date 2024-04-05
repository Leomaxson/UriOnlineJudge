# CMakeList.txt : CMake project for 1222, include source and define
# project specific logic here.

add_executable (1222 "1222.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1222 PROPERTY CXX_STANDARD 20)
endif()
