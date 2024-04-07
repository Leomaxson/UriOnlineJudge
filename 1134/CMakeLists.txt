# CMakeList.txt : CMake project for 1134, include source and define
# project specific logic here.

add_executable (1134 "1134.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1134 PROPERTY CXX_STANDARD 20)
endif()
