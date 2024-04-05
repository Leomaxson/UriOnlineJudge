# CMakeList.txt : CMake project for 1066, include source and define
# project specific logic here.

add_executable (1066 "1066.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1066 PROPERTY CXX_STANDARD 20)
endif()
