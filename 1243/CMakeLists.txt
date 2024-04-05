# CMakeList.txt : CMake project for 1243, include source and define
# project specific logic here.

add_executable (1243 "1243.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1243 PROPERTY CXX_STANDARD 20)
endif()
