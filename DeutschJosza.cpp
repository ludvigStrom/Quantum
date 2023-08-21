#include "DeutschJosza.h"

// Modify the constructor to accept an Oracle object by reference
DeutschJosza::DeutschJosza(Oracle& o, int numQubits) : oracle(o), n(numQubits) {}

bool DeutschJosza::isFunctionConstant() {
    // Step 1: Initialization
    QuantumRegister register1(n, 0); // n-qubit register initialized to |0>
    Qubit qubit2(1); // Single qubit initialized to |1>

    // Step 2: Apply Hadamard to each qubit
    for (int i = 0; i < n; i++) {
        register1.applyHadamardToQubit(i);
    }
    qubit2.applyHadamard();

    // Step 3: Apply the quantum oracle
    oracle.apply(register1, qubit2);

    // Step 4: Apply Hadamard again to the first register
    for (int i = 0; i < n; i++) {
        register1.applyHadamardToQubit(i);
    }

    // Step 5: Measurement
    for (int i = 0; i < n; i++) {
        if (register1.measure(i) != 0) {
            return false; // Function is balanced
        }
    }
    return true; // Function is constant
}