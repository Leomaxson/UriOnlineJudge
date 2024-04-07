# CMakeList.txt : CMake project for 1113, include source and define
# project specific logic here.

add_executable (1113 "1113.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1113 PROPERTY CXX_STANDARD 20)
endif()
