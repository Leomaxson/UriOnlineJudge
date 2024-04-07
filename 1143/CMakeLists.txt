# CMakeList.txt : CMake project for 1143, include source and define
# project specific logic here.

add_executable (1143 "1143.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1143 PROPERTY CXX_STANDARD 20)
endif()
