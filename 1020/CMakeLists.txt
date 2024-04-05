# CMakeList.txt : CMake project for 1020, include source and define
# project specific logic here.

add_executable (1020 "1020.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1020 PROPERTY CXX_STANDARD 20)
endif()
