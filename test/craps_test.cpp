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
TEST_CASE("Test for Sum of Two Die Rolls (2 to 12)")
{
    Die die1, die2;
   
    // Loop 10 times to test if the sum of two die rolls is between 2 and 12
    for (int i = 0; i < 10; ++i)
    {
        int roll1 = die1.roll();
        int roll2 = die2.roll();
        int sum = roll1 + roll2;
       
        REQUIRE(sum >= 2);  // Sum should be at least 2
        REQUIRE(sum <= 12);  // Sum should be at most 12
    }
}
