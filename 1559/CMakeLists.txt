# CMakeList.txt : CMake project for 1559, include source and define
# project specific logic here.

add_executable (1559 "1559.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1559 PROPERTY CXX_STANDARD 20)
endif()
