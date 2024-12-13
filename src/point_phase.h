//
#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"


class Point_Phase : public Phase {
public:
    Point_Phase(int p);
    RollOutcome get_outcome(Roll* roll) override;
private:
    int point;
};

#endif