# CMakeList.txt : CMake project for 1075, include source and define
# project specific logic here.

add_executable (1075 "1075.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1075 PROPERTY CXX_STANDARD 20)
endif()
