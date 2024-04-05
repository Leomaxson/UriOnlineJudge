# CMakeList.txt : CMake project for 1128, include source and define
# project specific logic here.

add_executable (1128 "1128.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1128 PROPERTY CXX_STANDARD 20)
endif()
