//
#include "die.h"

int Die::roll() {
    return (std::rand() % sides) + 1;
}