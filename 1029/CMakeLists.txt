# CMakeList.txt : CMake project for 1029, include source and define
# project specific logic here.

add_executable (1029 "1029.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1029 PROPERTY CXX_STANDARD 20)
endif()
