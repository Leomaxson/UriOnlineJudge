# CMakeList.txt : CMake project for 1168, include source and define
# project specific logic here.

add_executable (1168 "1168.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1168 PROPERTY CXX_STANDARD 20)
endif()
