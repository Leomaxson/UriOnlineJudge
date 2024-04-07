# CMakeList.txt : CMake project for 1153, include source and define
# project specific logic here.

add_executable (1153 "1153.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1153 PROPERTY CXX_STANDARD 20)
endif()
