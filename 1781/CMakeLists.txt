# CMakeList.txt : CMake project for 1781, include source and define
# project specific logic here.

add_executable (1781 "1781.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1781 PROPERTY CXX_STANDARD 20)
endif()
