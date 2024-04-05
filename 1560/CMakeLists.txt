# CMakeList.txt : CMake project for 1560, include source and define
# project specific logic here.

add_executable (1560 "1560.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1560 PROPERTY CXX_STANDARD 20)
endif()
