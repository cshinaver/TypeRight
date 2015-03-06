/*
 * main_unittests.cpp
 * Charles Shinaver
 * Main testing file
*/

#include "SDLWrapper.h"
#include "gtest/include/gtest/gtest.h"

// Test if window is instantiated
TEST(SDLTest, IsWindowCreated) {
    SDLWrapper sw;
    ASSERT_TRUE(sw.window != NULL);
}
