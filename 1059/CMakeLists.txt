# CMakeList.txt : CMake project for 1059, include source and define
# project specific logic here.

add_executable (1059 "1059.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1059 PROPERTY CXX_STANDARD 20)
endif()
