# CMakeList.txt : CMake project for 1042, include source and define
# project specific logic here.

add_executable (1042 "1042.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1042 PROPERTY CXX_STANDARD 20)
endif()
