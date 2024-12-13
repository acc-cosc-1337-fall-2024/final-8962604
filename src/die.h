//
#ifndef DIE_H
#define DIE_H

#include <cstdlib>  // for rand()
#include <ctime>    // for time()

class Die {
public:
    Die() { std::srand(std::time(0)); }  // Seed the random generator once
    int roll();
private:
    int sides {6};
};

#endif