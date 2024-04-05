# CMakeList.txt : CMake project for 1044, include source and define
# project specific logic here.

add_executable (1044 "1044.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1044 PROPERTY CXX_STANDARD 20)
endif()
