#pragma once

#include <vector>
#include "Qubit.h"

class QuantumRegister {
private:
    std::vector<Qubit> qubits;

public:
    // Constructor to initialize the quantum register with a given number of qubits, all set to a specific state
    QuantumRegister(int numQubits, int initialState = 0);

    // Apply a gate to a specific qubit in the register
    void applyGateToQubit(int qubitIndex, void (Qubit::* gate)());
    
    void applyCNOT(int controlQubitIndex, Qubit& targetQubit);

    // Get a specific qubit from the register
    Qubit& getQubit(int qubitIndex);

    // Measure a specific qubit in the register
    int measure(int qubitIndex);

    // Print the state of all qubits in the register
    void printAllStates() const;

    void applyHadamardToQubit(int index);
};
