#ifndef DEUTSCHJOSZA_H
#define DEUTSCHJOSZA_H

#include <iostream>
#include <vector>
#include <complex>
#include "Qubit.h"
#include "Oracle.h"

class DeutschJosza {
private:
    Oracle& oracle; // This is a black-box function. 
    int n; // Number of qubits in the first register

public:
    DeutschJosza(Oracle& o, int numQubits);

    bool isFunctionConstant();
};

#endif