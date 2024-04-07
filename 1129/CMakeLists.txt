# CMakeList.txt : CMake project for 1129, include source and define
# project specific logic here.

add_executable (1129 "1129.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1129 PROPERTY CXX_STANDARD 20)
endif()
