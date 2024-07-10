# CMakeList.txt : CMake project for 1023, include source and define
# project specific logic here.

add_executable (1023 "1023.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1023 PROPERTY CXX_STANDARD 20)
endif()
