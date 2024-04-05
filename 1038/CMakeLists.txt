# CMakeList.txt : CMake project for 1038, include source and define
# project specific logic here.

add_executable (1038 "1038.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1038 PROPERTY CXX_STANDARD 20)
endif()
