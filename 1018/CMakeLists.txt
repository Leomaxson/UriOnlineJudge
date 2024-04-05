# CMakeList.txt : CMake project for 1018, include source and define
# project specific logic here.

add_executable (1018 "1018.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1018 PROPERTY CXX_STANDARD 20)
endif()
