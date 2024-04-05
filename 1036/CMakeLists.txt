# CMakeList.txt : CMake project for 1036, include source and define
# project specific logic here.

add_executable (1036 "1036.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1036 PROPERTY CXX_STANDARD 20)
endif()
