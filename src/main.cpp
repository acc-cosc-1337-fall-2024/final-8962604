#include <iostream>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() {
    std::srand(std::time(0)); // Seed the random number generator once
    Die die1, die2;
    Shooter shooter;

    // Set the first roll to be 9 for expected output
    std::unique_ptr<Roll> roll = shooter.throw_dice(die1, die2);
    std::cout << "Rolled " << roll->roll_value() << ". Start of point phase." << std::endl;

    int point = roll->roll_value(); // Use the rolled value as the point for the point phase
    std::cout << "Roll until " << point << " or a 7 is rolled" << std::endl;

    // Set up the point phase
    Point_Phase point_phase(point);

    // Keep rolling until the point is matched or a 7 is rolled
    while (true) {
        roll = shooter.throw_dice(die1, die2);
        int rolled_value = roll->roll_value();
        std::cout << "Rolled " << rolled_value << ". ";

        RollOutcome outcome = point_phase.get_outcome(roll.get());

        if (outcome == RollOutcome::point) {
            std::cout << "Point matched!" << std::endl;
            break;
        } else if (outcome == RollOutcome::seven_out) {
            std::cout << "End of point phase." << std::endl;
            break;
        } else {
            std::cout << "Roll again!" << std::endl;
        }
    }

    // Display the rolled values
    shooter.display_rolled_values();
    
    return 0;
}