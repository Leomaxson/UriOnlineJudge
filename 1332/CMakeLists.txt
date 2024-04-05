# CMakeList.txt : CMake project for 1332, include source and define
# project specific logic here.

add_executable (1332 "1332.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1332 PROPERTY CXX_STANDARD 20)
endif()
