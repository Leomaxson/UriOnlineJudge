# CMakeList.txt : CMake project for 1071, include source and define
# project specific logic here.

add_executable (1071 "1071.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1071 PROPERTY CXX_STANDARD 20)
endif()
