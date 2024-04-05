# CMakeList.txt : CMake project for 1087, include source and define
# project specific logic here.

add_executable (1087 "1087.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1087 PROPERTY CXX_STANDARD 20)
endif()
