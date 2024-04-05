# CMakeList.txt : CMake project for 1161, include source and define
# project specific logic here.

add_executable (1161 "1161.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1161 PROPERTY CXX_STANDARD 20)
endif()
