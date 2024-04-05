# CMakeList.txt : CMake project for 1021, include source and define
# project specific logic here.

add_executable (1021 "1021.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1021 PROPERTY CXX_STANDARD 20)
endif()
