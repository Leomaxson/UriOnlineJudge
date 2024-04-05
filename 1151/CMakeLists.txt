# CMakeList.txt : CMake project for 1151, include source and define
# project specific logic here.

add_executable (1151 "1151.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1151 PROPERTY CXX_STANDARD 20)
endif()
