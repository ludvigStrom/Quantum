#ifndef ORACLE_H
#define ORACLE_H

#include "Qubit.h"  
#include "QuantumRegister.h" 

class Oracle {
public:
    // Constructor: Initializes the oracle with a hidden function type (constant or balanced)
    Oracle(bool isConstant);

    // Apply the oracle operation on the given qubit
    void apply(QuantumRegister& quantumRegister, Qubit& qubit);

private:
    bool constant;  // True if the hidden function is constant, false if it's balanced
};

#endif // ORACLE_H