# CMakeList.txt : CMake project for 1608, include source and define
# project specific logic here.

add_executable (1608 "1608.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1608 PROPERTY CXX_STANDARD 20)
endif()
