#include "Qubit.h"
#include <cassert>
#include <iostream>

void testApplyPauliX() {
    // Create a qubit and set it to the |0⟩ state
    Qubit q;
    q.setState(std::complex<double>(1, 0), std::complex<double>(0, 0));

    // Apply the Pauli-X gate
    q.applyPauliX();

    // Measure the qubit multiple times to ensure it's in the |1⟩ state
    int measurements = 1000;
    int countOne = 0;
    for (int i = 0; i < measurements; i++) {
        if (q.measure() == 1) {
            countOne++;
        }
    }

    // Assert that the qubit is in the |1⟩ state with high probability
    // (This is a probabilistic test since quantum measurements are probabilistic in nature)
    assert(countOne > 0.95 * measurements);

    std::cout << "testApplyPauliX passed!" << std::endl;
}

void testApplyPauliY() {
    // Test for |0⟩ state
    Qubit q1;
    q1.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set to |0⟩ state
    q1.applyPauliY(); // Apply Pauli-Y gate

    // Measure the qubit multiple times to ensure it's in the |1⟩ state
    int measurements = 1000;
    int countOne = 0;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 1) {
            countOne++;
        }
    }
    assert(countOne > 0.95 * measurements); // Assert that the qubit is in the |1⟩ state with high probability

    // Test for |1⟩ state
    Qubit q2;
    q2.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set to |1⟩ state
    q2.applyPauliY(); // Apply Pauli-Y gate

    // Measure the qubit multiple times to ensure it's in the |0⟩ state
    int countZero = 0;
    for (int i = 0; i < measurements; i++) {
        if (q2.measure() == 0) {
            countZero++;
        }
    }
    assert(countZero > 0.95 * measurements); // Assert that the qubit is in the |0⟩ state with high probability

    std::cout << "testApplyPauliY passed!" << std::endl;
}


void testApplyPauliZ() {
    // TODO: Implement test for Pauli-Z gate
}

void testApplyHadamard() {
    // TODO: Implement test for Hadamard gate
}

void testApplyPhase() {
    // Test for |0⟩ state
    Qubit q0;
    q0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set to |0⟩ state
    q0.applyPhase(); // Apply Phase gate

    // Measure the qubit multiple times to ensure it remains in the |0⟩ state
    int measurements = 1000;
    int countZero = 0;
    for (int i = 0; i < measurements; i++) {
        if (q0.measure() == 0) {
            countZero++;
        }
    }
    assert(countZero > 0.95 * measurements); // Assert that the qubit remains in the |0⟩ state with high probability

    // Test for |1⟩ state
    Qubit q1;
    q1.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set to |1⟩ state
    q1.applyPhase(); // Apply Phase gate

    // Measure the qubit multiple times to ensure it's in the i|1⟩ state
    int countOne = 0;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 1) {
            countOne++;
        }
    }
    assert(countOne > 0.95 * measurements); // Assert that the qubit is in the i|1⟩ state with high probability

    std::cout << "testApplyPhase passed!" << std::endl;
}


void testApplyTGate() {
    // TODO: Implement test for T-Gate
}

void testApplyCNOT() {
    // TODO: Implement test for CNOT gate
}

void testApplyControlledZ() {
    // TODO: Implement test for Controlled-Z gate
}

void testApplySwap() {
    // TODO: Implement test for Swap operation
}

void testMeasure() {
    // TODO: Implement test for qubit measurement
}
