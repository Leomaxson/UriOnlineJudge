# CMakeList.txt : CMake project for 1050, include source and define
# project specific logic here.

add_executable (1050 "1050.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1050 PROPERTY CXX_STANDARD 20)
endif()
