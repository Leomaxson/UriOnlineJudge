# CMakeList.txt : CMake project for 1072, include source and define
# project specific logic here.

add_executable (1072 "1072.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1072 PROPERTY CXX_STANDARD 20)
endif()
