# CMakeList.txt : CMake project for 1061, include source and define
# project specific logic here.

add_executable (1061 "1061.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1061 PROPERTY CXX_STANDARD 20)
endif()
