# CMakeList.txt : CMake project for 1073, include source and define
# project specific logic here.

add_executable (1073 "1073.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1073 PROPERTY CXX_STANDARD 20)
endif()
