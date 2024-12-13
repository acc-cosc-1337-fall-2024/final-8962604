#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.cpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Test for Die Rolls (1 to 6)")
{
    Die die;
   
    // Loop 10 times to test if die rolls return a value between 1 and 6
    for (int i = 0; i < 10; ++i)
    {
        int roll = die.roll();
        REQUIRE(roll >= 1);  // Die roll should be at least 1
        REQUIRE(roll <= 6);  // Die roll should be at most 6
    }
}
