# Quantum
The Quantum project provides a simple C++ implementation for quantum computing concepts, including qubits and Hermitian matrices.

## Features
Qubit Operations: The project provides a Qubit class that allows you to:
*  Initialize qubits and set their states.
* Apply various quantum gates such as Pauli-X, Pauli-Y, Pauli-Z, Hadamard, Phase, and T-Gate.
* Perform controlled operations like CNOT, Controlled-Z, and SWAP.
* Measure the state of a qubit.

## Hermitian Matrices: 
The HermitianMatrix class provides functionalities to:
* Initialize and manipulate Hermitian matrices.
* Check if a matrix is Hermitian.
* Print the matrix.
* Get the adjoint of the matrix.
* Multiply the matrix with a vector.

## Usage
### Qubit
```
Qubit q;
q.setState(std::complex<double>(1.0, 0.0), std::complex<double>(1.0, 0.0)); // Set to superposition
q.applyPauliX(); // Apply Pauli-X gate
q.printState();  // Print the resulting state
```

### Hermitian Matrix
```
HermitianMatrix matrix({
    {std::complex<double>(1, 0), std::complex<double>(2, 3)},
    {std::complex<double>(2, -3), std::complex<double>(4, 0)}
});
matrix.printMatrix();
std::cout << "Is Hermitian? " << (matrix.isHermitian() ? "Yes" : "No") << std::endl;
```

The repository also contains tests for both Qubit and HermitianMatrix classes.
