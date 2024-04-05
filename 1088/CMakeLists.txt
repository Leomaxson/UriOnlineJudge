# CMakeList.txt : CMake project for 1088, include source and define
# project specific logic here.

add_executable (1088 "1088.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1088 PROPERTY CXX_STANDARD 20)
endif()
