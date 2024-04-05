# CMakeList.txt : CMake project for 1855, include source and define
# project specific logic here.

add_executable (1855 "1855.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1855 PROPERTY CXX_STANDARD 20)
endif()
