cmake_minimum_required(VERSION 3.18.0)

project(file-diff C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb")

set(srcs "diff.cc") 
set(test-srcs "test.cc") 

add_subdirectory(file-list)

add_library(file-diff STATIC ${srcs})
target_link_libraries(file-diff file-list)

add_executable(${CMAKE_PROJECT_NAME}-test ${test-srcs})
target_link_libraries(${CMAKE_PROJECT_NAME}-test file-diff)
