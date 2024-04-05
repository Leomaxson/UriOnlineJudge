# CMakeList.txt : CMake project for 1000, include source and define
# project specific logic here.

add_executable (1000 "1000.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1000 PROPERTY CXX_STANDARD 20)
endif()
