# CMakeList.txt : CMake project for 1009, include source and define
# project specific logic here.

add_executable (1009 "1009.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1009 PROPERTY CXX_STANDARD 20)
endif()
