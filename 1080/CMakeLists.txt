# CMakeList.txt : CMake project for 1080, include source and define
# project specific logic here.

add_executable (1080 "1080.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1080 PROPERTY CXX_STANDARD 20)
endif()
