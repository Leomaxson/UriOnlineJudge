# CMakeList.txt : CMake project for 1351, include source and define
# project specific logic here.

add_executable (1351 "1351.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1351 PROPERTY CXX_STANDARD 20)
endif()
