# CMakeList.txt : CMake project for 1024, include source and define
# project specific logic here.

add_executable (1024 "1024.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1024 PROPERTY CXX_STANDARD 20)
endif()
