# CMakeList.txt : CMake project for 1286, include source and define
# project specific logic here.

add_executable (1286 "1286.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1286 PROPERTY CXX_STANDARD 20)
endif()
