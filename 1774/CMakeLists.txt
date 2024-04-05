# CMakeList.txt : CMake project for 1774, include source and define
# project specific logic here.

add_executable (1774 "1774.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1774 PROPERTY CXX_STANDARD 20)
endif()
