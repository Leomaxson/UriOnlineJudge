# CMakeList.txt : CMake project for 2545, include source and define
# project specific logic here.

add_executable (2545 "2545.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2545 PROPERTY CXX_STANDARD 20)
endif()
