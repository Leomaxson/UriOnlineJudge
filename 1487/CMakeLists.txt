# CMakeList.txt : CMake project for 1487, include source and define
# project specific logic here.

add_executable (1487 "1487.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1487 PROPERTY CXX_STANDARD 20)
endif()
