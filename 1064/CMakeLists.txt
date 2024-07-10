# CMakeList.txt : CMake project for 1064, include source and define
# project specific logic here.

add_executable (1064 "1064.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1064 PROPERTY CXX_STANDARD 20)
endif()
