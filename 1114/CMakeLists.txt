# CMakeList.txt : CMake project for 1114, include source and define
# project specific logic here.

add_executable (1114 "1114.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1114 PROPERTY CXX_STANDARD 20)
endif()
