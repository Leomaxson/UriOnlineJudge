# CMakeList.txt : CMake project for 1542, include source and define
# project specific logic here.

add_executable (1542 "1542.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1542 PROPERTY CXX_STANDARD 20)
endif()
