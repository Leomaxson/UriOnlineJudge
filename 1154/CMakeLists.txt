# CMakeList.txt : CMake project for 1154, include source and define
# project specific logic here.

add_executable (1154 "1154.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1154 PROPERTY CXX_STANDARD 20)
endif()
