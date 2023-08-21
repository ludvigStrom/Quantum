#ifndef BLOCHSPHEREASCII_H
#define BLOCHSPHEREASCII_H

#include "Qubit.h"
#include <iostream>
#include <cmath>

class BlochSphereASCII {
public:
    BlochSphereASCII(const Qubit& qubit);
    void draw();

private:
    const Qubit& q;
};

#endif // BLOCHSPHEREASCII_H
