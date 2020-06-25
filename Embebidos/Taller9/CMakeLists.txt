cmake_minimum_required (VERSION 3.10)

#define the project
project (libprand)
find_package(OpenMP REQUIRED)

#add lib subdirectory to build
add_subdirectory (lib)

#include directories to building path
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib)

# add the executable
add_executable (main src/main.c)

#link against required libraries
target_link_libraries(main PRIVATE OpenMP::OpenMP_C prand)

#install the binary
install (TARGETS main DESTINATION bin)

#package source generation
set(MAJOR "0")
set(MINOR "1")
set(PATCH "1")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${MAJOR}.${MINOR}.${PATCH}")
set(CPACK_SOURCE_IGNORE_FILES "/build/;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)
