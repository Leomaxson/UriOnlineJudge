# CMakeList.txt : CMake project for 1016, include source and define
# project specific logic here.

add_executable (1016 "1016.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1016 PROPERTY CXX_STANDARD 20)
endif()
