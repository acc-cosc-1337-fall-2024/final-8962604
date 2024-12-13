//
#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll {
public:
    Roll(Die& d1, Die& d2) : die1(d1), die2(d2), rolled_value(0) {}
    void roll_dice();
    int roll_value() const;
    int get_total() const; // Add this method
private:
    Die& die1;
    Die& die2;
    int rolled_value;
};

#endif