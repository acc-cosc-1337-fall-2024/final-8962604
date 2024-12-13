#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "point_phase.h"
#include "come_out_phase.h"
#include "phase.h"


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
TEST_CASE("Test for Shooter Roll (2 to 12)")
{
    Shooter shooter;
    Die d1, d2; // Create two dice objects
   
    // Loop 10 times to test if the shooter roll result is between 2 and 12
    for (int i = 0; i < 10; ++i)
    {
        // Use throw_dice to get a roll and retrieve the rolled value
        std::unique_ptr<Roll> roll = shooter.throw_dice(d1, d2);
        int roll_value = roll->roll_value(); // Assuming Roll has a roll_value() method
       
        REQUIRE(roll_value >= 2);  // Roll should be at least 2
        REQUIRE(roll_value <= 12); // Roll should be at most 12
    }
}
TEST_CASE("Test for ComeOutPhase Outcomes")
{
    Come_Out_Phase comeOutPhase;
    Die die1, die2; // Create dice objects

    // Loop 10 times to test that get_outcome returns expected values
    for (int i = 0; i < 10; ++i)
    {
        Roll roll(die1, die2); // Create a Roll object using dice
        roll.roll_dice(); // Roll the dice to get random values
        RollOutcome outcome = comeOutPhase.get_outcome(&roll); // Pass roll as a pointer
       
        REQUIRE(outcome == RollOutcome::natural ||
                outcome == RollOutcome::craps ||
                outcome == RollOutcome::point);
    }
}

TEST_CASE("Test for PointPhase Outcomes")
{
    int initial_point = 4; // Example initial point
    Point_Phase pointPhase(initial_point);
    Die die1, die2; // Create dice objects

    // Loop 10 times to test that get_outcome returns expected values
    for (int i = 0; i < 10; ++i)
    {
        Roll roll(die1, die2); // Create a Roll object using dice
        roll.roll_dice(); // Roll the dice to get random values
        RollOutcome outcome = pointPhase.get_outcome(&roll); // Pass roll as a pointer
       
        REQUIRE(outcome == RollOutcome::point ||
                outcome == RollOutcome::seven_out ||
                outcome == RollOutcome::nopoint);
    }
}
TEST_CASE("Complete End-to-End Test for Full Game Cycle (Shooter, ComeOutPhase, PointPhase)")
{
    Shooter shooter;
    Come_Out_Phase comeOutPhase;
    Die die1, die2; // Create dice objects for Roll
   
    // Simulate Shooter Roll (2 to 12)
    Roll shooterRoll(die1, die2); // Shooter roll uses dice objects
    shooterRoll.roll_dice(); // Roll the dice
    int shooterRollValue = shooterRoll.get_total(); // Get total of both dice
   
    REQUIRE(shooterRollValue >= 2);  // Shooter roll should be at least 2
    REQUIRE(shooterRollValue <= 12);  // Shooter roll should be at most 12
   
    // Simulate ComeOutPhase Outcome (natural, craps, or point)
    RollOutcome comeOutOutcome = comeOutPhase.get_outcome(&shooterRoll); // Pass roll as a pointer
    REQUIRE(comeOutOutcome == RollOutcome::natural ||
            comeOutOutcome == RollOutcome::craps ||
            comeOutOutcome == RollOutcome::point);
   
    // If ComeOutPhase results in a point, simulate PointPhase outcome
    if (comeOutOutcome == RollOutcome::point)
    {
        int point = shooterRollValue; // Set the point to the shooter's roll value
        Point_Phase pointPhase(point); // Initialize PointPhase with the point
       
        Roll pointRoll(die1, die2); // Create a Roll object for the point phase
        pointRoll.roll_dice(); // Roll the dice
        RollOutcome pointOutcome = pointPhase.get_outcome(&pointRoll); // Pass roll as a pointer
       
        REQUIRE(pointOutcome == RollOutcome::point ||
                pointOutcome == RollOutcome::seven_out ||
                pointOutcome == RollOutcome::nopoint);
    }
}
