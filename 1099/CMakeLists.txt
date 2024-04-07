# CMakeList.txt : CMake project for 1099, include source and define
# project specific logic here.

add_executable (1099 "1099.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1099 PROPERTY CXX_STANDARD 20)
endif()
