# CMakeList.txt : CMake project for 2532, include source and define
# project specific logic here.

add_executable (2532 "2532.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2532 PROPERTY CXX_STANDARD 20)
endif()
