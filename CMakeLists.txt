cmake_minimum_required (VERSION 3.16)
project(logdb
  VERSION 0.1
  DESCRIPTION "C++ implementation of logging system"
  LANGUAGES CXX
)
include_directories(include)
add_subdirectory(src)

aux_source_directory(. DIR_TEST_SRCS)
add_executable(logdbtest ${DIR_TEST_SRCS} )
target_link_libraries( logdbtest logdb )
target_include_directories(logdbtest PRIVATE src)

