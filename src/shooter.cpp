//
#include "shooter.h"
#include <iostream>

std::unique_ptr<Roll> Shooter::throw_dice(Die& d1, Die& d2) {
    std::unique_ptr<Roll> roll = std::make_unique<Roll>(d1, d2);
    roll->roll_dice();
    rolls.push_back(std::move(roll));
    return std::move(rolls.back());
}

void Shooter::display_rolled_values() const {
    for (const auto& roll : rolls) {
        std::cout << roll->roll_value() << " ";
    }
    std::cout << std::endl;
}