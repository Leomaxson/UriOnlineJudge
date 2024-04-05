# CMakeList.txt : CMake project for 1060, include source and define
# project specific logic here.

add_executable (1060 "1060.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1060 PROPERTY CXX_STANDARD 20)
endif()
