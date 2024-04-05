# CMakeList.txt : CMake project for 1362, include source and define
# project specific logic here.

add_executable (1362 "1362.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1362 PROPERTY CXX_STANDARD 20)
endif()
