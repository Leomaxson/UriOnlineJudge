# CMakeList.txt : CMake project for 1115, include source and define
# project specific logic here.

add_executable (1115 "1115.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1115 PROPERTY CXX_STANDARD 20)
endif()
