# CMakeList.txt : CMake project for 1045, include source and define
# project specific logic here.

add_executable (1045 "1045.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1045 PROPERTY CXX_STANDARD 20)
endif()
