# CMakeList.txt : CMake project for 1096, include source and define
# project specific logic here.

add_executable (1096 "1096.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1096 PROPERTY CXX_STANDARD 20)
endif()
