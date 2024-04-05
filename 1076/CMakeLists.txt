# CMakeList.txt : CMake project for 1076, include source and define
# project specific logic here.

add_executable (1076 "1076.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1076 PROPERTY CXX_STANDARD 20)
endif()
