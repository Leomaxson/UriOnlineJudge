# CMakeList.txt : CMake project for 1276, include source and define
# project specific logic here.

add_executable (1276 "1276.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1276 PROPERTY CXX_STANDARD 20)
endif()
