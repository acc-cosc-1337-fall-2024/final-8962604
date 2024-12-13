//
#include "come_out_phase.h"
#include "roll.h"  // Include Roll.h here

RollOutcome Come_Out_Phase::get_outcome(Roll* roll) {
    int value = roll->roll_value();
    if (value == 7 || value == 11) {
        return RollOutcome::natural;
    } else if (value == 2 || value == 3 || value == 12) {
        return RollOutcome::craps;
    } else {
        return RollOutcome::point;
    }
}