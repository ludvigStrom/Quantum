#include "Qubit.h"
#include <cassert>
#include <iostream>

void testApplyPauliX() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testApplyPauliX..." << std::endl;

    // Initialization
    Qubit q;
    std::cout << "Initialized a new qubit." << std::endl;

    q.setState(std::complex<double>(1, 0), std::complex<double>(0, 0));
    std::cout << "Set the qubit state to |0>." << std::endl;

    // Apply the Pauli-X gate
    q.applyPauliX();
    std::cout << "Applied the Pauli-X gate." << std::endl;

    // Measurement
    int measurements = 1000;
    int countOne = 0;
    std::cout << "Starting " << measurements << " measurements..." << std::endl;

    for (int i = 0; i < measurements; i++) {
        if (q.measure() == 1) {
            countOne++;
        }
    }

    std::cout << "Completed measurements. Count of |1> states: " << countOne << std::endl;

    // Verification
    if (countOne > 0.95 * measurements) {
        std::cout << "The qubit is in the |1> state with high probability." << std::endl;
    }
    else {
        std::cout << "The qubit is not in the |1> state with high probability. Test might fail." << std::endl;
    }

    assert(countOne > 0.95 * measurements);
    std::cout << "testApplyPauliX passed!" << std::endl;
}


void testApplyPauliY() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testApplyPauliY..." << std::endl;

    // Test for |0⟩ state
    Qubit q1;
    q1.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set to |0⟩ state
    std::cout << "Initialized q1 and set to |0> state." << std::endl;

    q1.applyPauliY(); // Apply Pauli-Y gate
    std::cout << "Applied Pauli-Y gate to q1." << std::endl;

    // Measure the qubit multiple times to ensure it's in the |1⟩ state
    int measurements = 1000;
    int countOne = 0;
    std::cout << "Starting " << measurements << " measurements for q1..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 1) {
            countOne++;
        }
    }
    std::cout << "Completed measurements for q1. Count of |1> states: " << countOne << std::endl;
    assert(countOne > 0.95 * measurements); // Assert that the qubit is in the |1⟩ state with high probability

    // Test for |1⟩ state
    Qubit q2;
    q2.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set to |1⟩ state
    std::cout << "Initialized q2 and set to |1> state." << std::endl;

    q2.applyPauliY(); // Apply Pauli-Y gate
    std::cout << "Applied Pauli-Y gate to q2." << std::endl;

    // Measure the qubit multiple times to ensure it's in the |0⟩ state
    int countZero = 0;
    std::cout << "Starting " << measurements << " measurements for q2..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q2.measure() == 0) {
            countZero++;
        }
    }
    std::cout << "Completed measurements for q2. Count of |0> states: " << countZero << std::endl;
    assert(countZero > 0.95 * measurements); // Assert that the qubit is in the |0⟩ state with high probability

    std::cout << "testApplyPauliY passed!" << std::endl;
}

void testApplyPauliZ() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testApplyPauliZ..." << std::endl;

    // Test for |0⟩ state
    Qubit q0;
    q0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set to |0⟩ state
    std::cout << "Initialized q0 and set to |0> state." << std::endl;

    q0.applyPauliZ(); // Apply Pauli-Z gate
    std::cout << "Applied Pauli-Z gate to q0." << std::endl;

    // Measure the qubit multiple times to ensure it remains in the |0⟩ state
    int measurements = 1000;
    int countZero = 0;
    std::cout << "Starting " << measurements << " measurements for q0..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q0.measure() == 0) {
            countZero++;
        }
    }
    std::cout << "Completed measurements for q0. Count of |0> states: " << countZero << std::endl;
    assert(countZero > 0.95 * measurements); // Assert that the qubit remains in the |0⟩ state with high probability

    // Test for |1⟩ state
    Qubit q1;
    q1.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set to |1⟩ state
    std::cout << "Initialized q1 and set to |1> state." << std::endl;

    q1.applyPauliZ(); // Apply Pauli-Z gate
    std::cout << "Applied Pauli-Z gate to q1." << std::endl;

    // Measure the qubit multiple times to ensure it's in the -|1⟩ state
    int countOne = 0;
    std::cout << "Starting " << measurements << " measurements for q1..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 1) {
            countOne++;
        }
    }
    std::cout << "Completed measurements for q1. Count of |1> states: " << countOne << std::endl;
    assert(countOne > 0.95 * measurements); // Assert that the qubit is in the -|1⟩ state with high probability

    std::cout << "testApplyPauliZ passed!" << std::endl;
}


void testApplyHadamard() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testApplyHadamard..." << std::endl;

    // Test for |0⟩ state
    Qubit q0;
    q0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set to |0⟩ state
    std::cout << "Initialized q0 and set to |0> state." << std::endl;

    q0.applyHadamard(); // Apply Hadamard gate
    std::cout << "Applied Hadamard gate to q0." << std::endl;

    // Measure the qubit multiple times to ensure it's in a superposition of |0⟩ and |1⟩
    int measurements = 1000;
    int countZero = 0;
    int countOne = 0;
    std::cout << "Starting " << measurements << " measurements for q0..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q0.measure() == 0) {
            countZero++;
        }
        else {
            countOne++;
        }
    }
    std::cout << "Completed measurements for q0. Count of |0> states: " << countZero << ", Count of |1> states: " << countOne << std::endl;
    assert(countZero > 0.4 * measurements && countZero < 0.6 * measurements); // Assert that the qubit is roughly equally likely to be in |0⟩ or |1⟩

    // Test for |1⟩ state
    Qubit q1;
    q1.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set to |1⟩ state
    std::cout << "Initialized q1 and set to |1> state." << std::endl;

    q1.applyHadamard(); // Apply Hadamard gate
    std::cout << "Applied Hadamard gate to q1." << std::endl;

    // Measure the qubit multiple times to ensure it's in a superposition of |0⟩ and |1⟩
    countZero = 0;
    countOne = 0;
    std::cout << "Starting " << measurements << " measurements for q1..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 0) {
            countZero++;
        }
        else {
            countOne++;
        }
    }
    std::cout << "Completed measurements for q1. Count of |0> states: " << countZero << ", Count of |1> states: " << countOne << std::endl;
    assert(countOne > 0.4 * measurements && countOne < 0.6 * measurements); // Assert that the qubit is roughly equally likely to be in |0⟩ or |1⟩

    std::cout << "testApplyHadamard passed!" << std::endl;
}


void testApplyPhase() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testApplyPhase..." << std::endl;

    // Test for |0⟩ state
    Qubit q0;
    q0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set to |0⟩ state
    std::cout << "Initialized q0 and set to |0> state." << std::endl;

    q0.applyPhase(); // Apply Phase gate
    std::cout << "Applied Phase gate to q0." << std::endl;

    // Measure the qubit multiple times to ensure it remains in the |0⟩ state
    int measurements = 1000;
    int countZero = 0;
    std::cout << "Starting " << measurements << " measurements for q0..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q0.measure() == 0) {
            countZero++;
        }
    }
    std::cout << "Completed measurements for q0. Count of |0> states: " << countZero << std::endl;
    assert(countZero > 0.95 * measurements); // Assert that the qubit remains in the |0⟩ state with high probability

    // Test for |1⟩ state
    Qubit q1;
    q1.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set to |1⟩ state
    std::cout << "Initialized q1 and set to |1> state." << std::endl;

    q1.applyPhase(); // Apply Phase gate
    std::cout << "Applied Phase gate to q1." << std::endl;

    // Measure the qubit multiple times to ensure it's in the i|1⟩ state
    int countOne = 0;
    std::cout << "Starting " << measurements << " measurements for q1..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 1) {
            countOne++;
        }
    }
    std::cout << "Completed measurements for q1. Count of |1> states: " << countOne << std::endl;
    assert(countOne > 0.95 * measurements); // Assert that the qubit is in the i|1⟩ state with high probability

    std::cout << "testApplyPhase passed!" << std::endl;
}

void testApplyTGate() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testApplyTGate..." << std::endl;

    // Test for |0⟩ state
    Qubit q0;
    q0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set to |0⟩ state
    std::cout << "Initialized q0 and set to |0> state." << std::endl;

    q0.applyTGate(); // Apply T-gate
    std::cout << "Applied T-gate to q0." << std::endl;

    // Measure the qubit multiple times to ensure it remains in the |0⟩ state
    int measurements = 1000;
    int countZero = 0;
    std::cout << "Starting " << measurements << " measurements for q0..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q0.measure() == 0) {
            countZero++;
        }
    }
    std::cout << "Completed measurements for q0. Count of |0> states: " << countZero << std::endl;
    assert(countZero == measurements); // Assert that the qubit remains in the |0⟩ state

    // Test for |1⟩ state
    Qubit q1;
    q1.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set to |1⟩ state
    std::cout << "Initialized q1 and set to |1> state." << std::endl;

    q1.applyTGate(); // Apply T-gate
    std::cout << "Applied T-gate to q1." << std::endl;

    // Measure the qubit multiple times to ensure it's in the e^{i\pi/4}|1⟩ state
    int countOne = 0;
    std::cout << "Starting " << measurements << " measurements for q1..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 1) {
            countOne++;
        }
    }
    std::cout << "Completed measurements for q1. Count of |1> states: " << countOne << std::endl;
    assert(countOne == measurements); // Assert that the qubit remains in the |1⟩ state, but with a phase applied

    std::cout << "testApplyTGate passed!" << std::endl;
}



void testApplyCNOT() {
    std::cout << "\n___________________________" << std::endl;
	std::cout << "Starting testApplyCNOT..." << std::endl;
    
    // Test for control qubit in |0⟩ state and target qubit in |0⟩ state
    Qubit control0, target0;
    control0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set control to |0⟩ state
    target0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set target to |0⟩ state
    Qubit::applyCNOT(control0, target0); // Apply CNOT gate

    assert(control0.measure() == 0 && target0.measure() == 0); // Assert that the state remains |00⟩

    // Test for control qubit in |0⟩ state and target qubit in |1⟩ state
    Qubit control1, target1;
    control1.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set control to |0⟩ state
    target1.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set target to |1⟩ state
    Qubit::applyCNOT(control1, target1); // Apply CNOT gate

    assert(control1.measure() == 0 && target1.measure() == 1); // Assert that the state remains |01⟩

    // Test for control qubit in |1⟩ state and target qubit in |0⟩ state
    Qubit control2, target2;
    control2.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set control to |1⟩ state
    target2.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set target to |0⟩ state
    Qubit::applyCNOT(control2, target2); // Apply CNOT gate

    assert(control2.measure() == 1 && target2.measure() == 1); // Assert that the state becomes |11⟩

    // Test for control qubit in |1⟩ state and target qubit in |1⟩ state
    Qubit control3, target3;
    control3.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set control to |1⟩ state
    target3.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set target to |1⟩ state
    Qubit::applyCNOT(control3, target3); // Apply CNOT gate

    assert(control3.measure() == 1 && target3.measure() == 0); // Assert that the state becomes |10⟩

    std::cout << "testApplyCNOT passed!" << std::endl;
}

void testApplyControlledZ() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testApplyControlledZ..." << std::endl;

    // Test when control qubit is |0⟩ (no change should occur)
    Qubit control0, target0;
    control0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set control to |0⟩ state
    std::cout << "Initialized control0 and set to |0> state." << std::endl;

    target0.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set target to |0⟩ state
    std::cout << "Initialized target0 and set to |0> state." << std::endl;

    Qubit::applyControlledZ(control0, target0);
    std::cout << "Applied Controlled-Z gate with control0 as control and target0 as target." << std::endl;

    // After measurement, target0 should still be |0⟩ with high probability
    int measurements = 1000;
    int countZero = 0;
    std::cout << "Starting " << measurements << " measurements for target0..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (target0.measure() == 0) {
            countZero++;
        }
    }
    std::cout << "Completed measurements for target0. Count of |0> states: " << countZero << std::endl;
    assert(countZero > 0.95 * measurements);

    // Test when control qubit is |1⟩ (Pauli-Z should be applied to target)
    Qubit control1, target1;
    control1.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set control to |1⟩ state
    std::cout << "Initialized control1 and set to |1> state." << std::endl;

    target1.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set target to |0⟩ state
    std::cout << "Initialized target1 and set to |0> state." << std::endl;

    Qubit::applyControlledZ(control1, target1);
    std::cout << "Applied Controlled-Z gate with control1 as control and target1 as target." << std::endl;

    // After measurement, target1 should still be |0⟩ with high probability (since Pauli-Z doesn't change |0⟩ state)
    countZero = 0;
    std::cout << "Starting " << measurements << " measurements for target1..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (target1.measure() == 0) {
            countZero++;
        }
    }
    std::cout << "Completed measurements for target1. Count of |0> states: " << countZero << std::endl;
    assert(countZero > 0.95 * measurements);

    std::cout << "testApplyControlledZ passed!" << std::endl;
}

void testApplySwap() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testApplySwap..." << std::endl;

    // Initialize two qubits with different states
    Qubit q1, q2;
    q1.setState(std::complex<double>(1, 0), std::complex<double>(0, 0)); // Set q1 to |0⟩ state
    std::cout << "Initialized q1 and set to |0> state." << std::endl;

    q2.setState(std::complex<double>(0, 0), std::complex<double>(1, 0)); // Set q2 to |1⟩ state
    std::cout << "Initialized q2 and set to |1> state." << std::endl;

    // Apply the swap operation
    Qubit::applySwap(q1, q2);
    std::cout << "Applied SWAP gate between q1 and q2." << std::endl;

    // After the swap, q1 should be in the |1⟩ state and q2 should be in the |0⟩ state
    int measurements = 1000;
    int countQ1One = 0;
    int countQ2Zero = 0;
    std::cout << "Starting " << measurements << " measurements for q1 and q2..." << std::endl;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 1) {
            countQ1One++;
        }
        if (q2.measure() == 0) {
            countQ2Zero++;
        }
    }
    std::cout << "Completed measurements. Count of |1> states for q1: " << countQ1One << std::endl;
    std::cout << "Count of |0> states for q2: " << countQ2Zero << std::endl;

    // Assert that q1 is in the |1⟩ state and q2 is in the |0⟩ state with high probability
    assert(countQ1One > 0.95 * measurements);
    assert(countQ2Zero > 0.95 * measurements);

    std::cout << "testApplySwap passed!" << std::endl;
}

void testMeasure() {
    std::cout << "\n___________________________" << std::endl;    
    std::cout << "Starting testMeasure...";
    
    // Create a qubit in a superposition state
    Qubit q;
    q.setState(std::complex<double>(1.0, 0.0), std::complex<double>(1.0, 0.0)); // Set to superposition (|0⟩ + |1⟩)/sqrt(2)
    std::cout << "Initialized qubit in superposition state (|0> + |1>)/sqrt(2)\n";

    // Measure the qubit multiple times to get the probabilities of |0⟩ and |1⟩ states
    int measurements = 1000;
    int countZero = 0;
    int countOne = 0;
    for (int i = 0; i < measurements; i++) {
        if (q.measure() == 0) {
            countZero++;
        }
        else {
            countOne++;
        }
    }

    std::cout << "After " << measurements << " measurements:\n";
    std::cout << "|0> was measured " << countZero << " times (" << (double)countZero / measurements * 100 << "%)\n";
    std::cout << "|1> was measured " << countOne << " times (" << (double)countOne / measurements * 100 << "%)\n";

    // Assert that the qubit collapses to |0⟩ and |1⟩ states with roughly equal probabilities
    assert(countZero > 0.4 * measurements && countZero < 0.6 * measurements);
    assert(countOne > 0.4 * measurements && countOne < 0.6 * measurements);

    // Create another qubit and set it to the |1⟩ state
    Qubit q1;
    q1.setState(std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0)); // Set to |1⟩ state
    std::cout << "\nInitialized another qubit in |1> state\n";

    // Measure the qubit multiple times to ensure it's always in the |1⟩ state
    countOne = 0;
    for (int i = 0; i < measurements; i++) {
        if (q1.measure() == 1) {
            countOne++;
        }
    }
    
    std::cout << "After " << measurements << " measurements of the second qubit:\n";
    std::cout << "|1> was measured " << countOne << " times (" << (double)countOne / measurements * 100 << "%)\n";

    // Assert that the qubit is always in the |1⟩ state
    assert(countOne == measurements);

    std::cout << "testMeasure passed!" << std::endl;
}

