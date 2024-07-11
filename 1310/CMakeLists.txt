# CMakeList.txt : CMake project for 1310, include source and define
# project specific logic here.

add_executable (1310 "1310.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1310 PROPERTY CXX_STANDARD 20)
endif()
