# CMakeList.txt : CMake project for 1132, include source and define
# project specific logic here.

add_executable (1132 "1132.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1132 PROPERTY CXX_STANDARD 20)
endif()
