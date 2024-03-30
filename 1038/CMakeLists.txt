# CMakeList.txt : CMake project for 1000, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (1038 "1038.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 1038 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
