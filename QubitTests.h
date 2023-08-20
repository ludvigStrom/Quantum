#ifndef QUBIT_TESTS_H
#define QUBIT_TESTS_H

#include "Qubit.h"
#include <cassert>
#include <iostream>

// Function declarations for testing various qubit operations

void testApplyPauliX();
void testApplyPauliY();
void testApplyPauliZ();
void testApplyHadamard();
void testApplyPhase();
void testApplyTGate();
void testApplyCNOT();
void testApplyControlledZ();
void testApplySwap();
void testMeasure();

#endif // QUBIT_TESTS_H