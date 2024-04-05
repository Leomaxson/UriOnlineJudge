# CMakeList.txt : CMake project for 1084, include source and define
# project specific logic here.

add_executable (1084 "1084.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1084 PROPERTY CXX_STANDARD 20)
endif()
