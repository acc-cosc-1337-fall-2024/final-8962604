//
#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H

#include "phase.h"

class Come_Out_Phase : public Phase {
public:
    RollOutcome get_outcome(Roll* roll) override;
};

#endif