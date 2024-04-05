# CMakeList.txt : CMake project for 1719, include source and define
# project specific logic here.

add_executable (1719 "1719.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1719 PROPERTY CXX_STANDARD 20)
endif()
