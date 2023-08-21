// Qubit.h

#pragma once

#include <iostream>
#include <complex>
#include <cmath>
#include <cstdlib>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Qubit {
private:
    std::complex<double> alpha;  // Coefficient for |0⟩ state
    std::complex<double> beta;   // Coefficient for |1⟩ state

public:
    Qubit();
    Qubit(int initialState);
    void setState(std::complex<double> a, std::complex<double> b);
    void applyPauliX();
    void applyPauliZ();
    void applyPauliY();
    void applyHadamard();
    void applyPhase();
    void applyTGate();
    static void applyCNOT(Qubit& control, Qubit& target);
    static void applyControlledZ(Qubit& control, Qubit& target);
    static void applySwap(Qubit& q1, Qubit& q2);
    int measure();
    void printState() const;
};
