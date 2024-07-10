# CMakeList.txt : CMake project for 1067, include source and define
# project specific logic here.

add_executable (1067 "1067.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1067 PROPERTY CXX_STANDARD 20)
endif()
