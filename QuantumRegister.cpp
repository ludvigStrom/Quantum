#include "QuantumRegister.h"

QuantumRegister::QuantumRegister(int numQubits, int initialState) {
    for (int i = 0; i < numQubits; i++) {
        qubits.push_back(Qubit());
        if (initialState == 1) {
            qubits.back().applyPauliX();  // Set qubit to |1⟩ state
        }
    }
}

void QuantumRegister::applyGateToQubit(int qubitIndex, void (Qubit::* gate)()) {
    (qubits[qubitIndex].*gate)();
}

void QuantumRegister::applyCNOT(int controlQubitIndex, Qubit& targetQubit) {
    // Check if the control qubit is in the |1> state
    if (qubits[controlQubitIndex].isSet()) {  // isSet() is a method in the Qubit class that checks if the qubit is in the |1> state
        targetQubit.applyPauliX();  // Apply the Pauli-X gate to the target qubit
    }
}

Qubit& QuantumRegister::getQubit(int qubitIndex) {
    return qubits[qubitIndex];
}

int QuantumRegister::measure(int qubitIndex) {
    return qubits[qubitIndex].measure();
}

void QuantumRegister::printAllStates() const {
    for (const auto& qubit : qubits) {
        qubit.printState();
    }
}

void QuantumRegister::applyHadamardToQubit(int index) {
    if (index >= 0 && index < qubits.size()) {
        qubits[index].applyHadamard();
    }
    else {
        std::cerr << "Error: Invalid qubit index." << std::endl;
    }
}