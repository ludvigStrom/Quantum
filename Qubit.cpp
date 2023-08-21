// Qubit.cpp

#include "Qubit.h"

// Constructor: Initializes the qubit to the |0⟩ state by default
Qubit::Qubit() : alpha(1.0), beta(0.0) {}

// Constructor: Initializes the qubit to the |0⟩ or |1⟩ state
Qubit::Qubit(int initialState) {
    if (initialState == 0) {
        alpha = 1.0;
        beta = 0.0;
    }
    else if (initialState == 1) {
        alpha = 0.0;
        beta = 1.0;
    }
    else {
        std::cerr << "Error: Invalid initial state for qubit. Must be 0 or 1." << std::endl;
        // Default to |0⟩ state
        alpha = 1.0;
        beta = 0.0;
    }
}


bool Qubit::isSet() const {
    // Check if the qubit is in the |1⟩ state
    return std::norm(beta) == 1.0;
}

// Set the qubit state using coefficients for |0⟩ and |1⟩ states
void Qubit::setState(std::complex<double> a, std::complex<double> b) {
    double norm = std::sqrt(std::norm(a) + std::norm(b));
    if (norm == 0) {
        std::cerr << "Error: Invalid state." << std::endl;
        return;
    }
    alpha = a / norm;
    beta = b / norm;
}

// Apply the Pauli-X (NOT) gate
void Qubit::applyPauliX() {
    std::swap(alpha, beta);
}

// Apply the Pauli-Z gate
void Qubit::applyPauliZ() {
    beta *= -1;
}

// Apply the Hadamard gate
void Qubit::applyHadamard() {
    std::complex<double> newAlpha = (alpha + beta) / std::sqrt(2.0);
    std::complex<double> newBeta = (alpha - beta) / std::sqrt(2.0);
    alpha = newAlpha;
    beta = newBeta;
}

// Pauli-Y Gate:
void Qubit::applyPauliY() {
    std::complex<double> newAlpha = std::complex<double>(0, 1) * beta;
    std::complex<double> newBeta = -std::complex<double>(0, 1) * alpha;
    alpha = newAlpha;
    beta = newBeta;
}

void Qubit::applyPhase() {
    beta *= std::complex<double>(0, 1);
}

void Qubit::applyTGate() {
    beta *= std::exp(std::complex<double>(0, M_PI / 4.0));
}

void Qubit::applyCNOT(Qubit& control, Qubit& target) {
    if (std::norm(control.alpha) < 0.5) {  // If control qubit is |1⟩
        target.applyPauliX();
    }
}

void Qubit::applyControlledZ(Qubit& control, Qubit& target) {
    if (std::norm(control.alpha) < 0.5 && std::norm(target.alpha) < 0.5) {
        target.applyPauliZ();
    }
}

void Qubit::applySwap(Qubit& q1, Qubit& q2) {
    std::swap(q1.alpha, q2.alpha);
    std::swap(q1.beta, q2.beta);
}

// Measure the qubit in the computational basis
int Qubit::measure() {
    double probabilityZero = std::norm(alpha);
    double random = ((double)rand() / (RAND_MAX));
    if (random < probabilityZero) {
        return 0;
    }
    else {
        return 1;
    }
}

// Print the qubit state
void Qubit::printState() const {
    std::cout << "Qubit state: " << alpha << "|0> + " << beta << "|1>" << std::endl;
}

std::complex<double> Qubit::getAlpha() const {
    return alpha;
}

std::complex<double> Qubit::getBeta() const {
    return beta;
}