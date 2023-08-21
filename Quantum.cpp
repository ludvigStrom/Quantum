// Quantum.cpp : Defines the entry point for the application.
//

#include "Quantum.h"
#include "Qubit.h"  
#include "HermitianMatrixTests.h"
#include "QubitTests.h"
#include "Oracle.h"
#include "DeutschJosza.h"


using namespace std;

int main()
{
    Qubit q;
    q.setState(std::complex<double>(1.0, 0.0), std::complex<double>(1.0, 0.0)); // Set to superposition
    q.applyPauliX(); // Apply Pauli-X gate
    cout << "Quantum state:" << endl;
    q.printState();  // Print the resulting state

    // Test HermitianMatrix
    HermitianMatrix matrix({
        {std::complex<double>(1, 0), std::complex<double>(2, 3)},
        {std::complex<double>(2, -3), std::complex<double>(4, 0)}
        });

    std::cout << "Matrix:" << std::endl;
    matrix.printMatrix();
    std::cout << "Is Hermitian? " << (matrix.isHermitian() ? "Yes" : "No") << std::endl;

    // HermitianMatrix tests
    cout << "\nRunning HermitianMatrix tests...\n";
    testIsHermitian();
    testGetAdjoint();
    testMultiply();
    cout << "All HermitianMatrix tests passed!" << endl;

	// Qubit tests
    testApplyPauliX();
    testApplyPauliY();
    testApplyPauliZ();
    testApplyPhase();
    testApplyHadamard();
    testApplyTGate();
    testApplyControlledZ();
    testApplySwap();
    testMeasure();

    Oracle myOracle(true);  // or Oracle myOracle(false);

    DeutschJosza dj(myOracle, 3); // Let's assume 3 qubits for this example
    if (dj.isFunctionConstant()) {
        std::cout << "The function is constant." << std::endl;
    }
    else {
        std::cout << "The function is balanced." << std::endl;
    }

    return 0;

}