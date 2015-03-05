cmake_minimum_required(VERSION 2.6)

# Cmake options
option(test "Build all tests." ON) # Makes boolean "test" available
enable_testing()

set(PROJECT_NAME TypeRight)
project(${PROJECT_NAME})

##################################
# Normal Libraries & Executables #
##################################
add_library(sample1_lib sample1.cc)

###########
# Testing #
###########
add_subdirectory(gtest)


# Include gtest library
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(sample1test sample1_unittest.cc)
target_link_libraries(sample1test sample1_lib gtest gtest_main)

add_test(sample1test sample1test)
