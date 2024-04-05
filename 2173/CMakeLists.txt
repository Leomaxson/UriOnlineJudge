# CMakeList.txt : CMake project for 2173, include source and define
# project specific logic here.

add_executable (2173 "2173.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2173 PROPERTY CXX_STANDARD 20)
endif()
