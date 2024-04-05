# CMakeList.txt : CMake project for 1017, include source and define
# project specific logic here.

add_executable (1017 "1017.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1017 PROPERTY CXX_STANDARD 20)
endif()
