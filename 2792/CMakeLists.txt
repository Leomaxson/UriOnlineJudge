# CMakeList.txt : CMake project for 2792, include source and define
# project specific logic here.

add_executable (2792 "2792.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2792 PROPERTY CXX_STANDARD 20)
endif()
