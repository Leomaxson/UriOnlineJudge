# CMakeList.txt : CMake project for 1190, include source and define
# project specific logic here.

add_executable (1190 "1190.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1190 PROPERTY CXX_STANDARD 20)
endif()
