//
/* Shooter.h */
#ifndef SHOOTER_H
#define SHOOTER_H

#include "roll.h"
#include <vector>
#include <memory> // for smart pointers

class Shooter {
public:
    std::unique_ptr<Roll> throw_dice(Die& d1, Die& d2);
    void display_rolled_values() const;
private:
    std::vector<std::unique_ptr<Roll>> rolls;
};

#endif