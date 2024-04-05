# CMakeList.txt : CMake project for 1028, include source and define
# project specific logic here.

add_executable (1028 "1028.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1028 PROPERTY CXX_STANDARD 20)
endif()
