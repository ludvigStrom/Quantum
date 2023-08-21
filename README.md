# Quantum
The Quantum project provides a simple C++ implementation for quantum computing concepts, including **qubits** and **Hermitian matrices**.

## Features
Qubit Operations: The project provides a Qubit class that allows you to:
*  Initialize qubits and set their states.
* Apply various quantum gates such as Pauli-X, Pauli-Y, Pauli-Z, Hadamard, Phase, and T-Gate.
* Perform controlled operations like CNOT, Controlled-Z, and SWAP.
* Measure the state of a qubit.

### Quantum Register
The `QuantumRegister` class allows for:
* Initialization of a quantum register with multiple qubits.
* Application of quantum gates to specific qubits within the register.
* Controlled operations between qubits in the register and external qubits.

### DeutschJosza Algorithm
The project provides an implementation of the DeutschJosza algorithm, which determines if a given function is constant or balanced using quantum principles.

## Hermitian Matrices: 
The HermitianMatrix class provides functionalities to:
* Initialize and manipulate Hermitian matrices.
* Check if a matrix is Hermitian.
* Print the matrix.
* Get the adjoint of the matrix.
* Multiply the matrix with a vector.

## Usage
To clone the repository along with its submodule dependencies, use:
```
git clone --recursive https://github.com/ludvigStrom/Quantum
```

To update the submodules to the latest version:
```
git submodule foreach git pull origin master
```


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

### DeutschJosza
Oracle oracle(false); // Initialize a balanced oracle
DeutschJosza dj(oracle, 2); // Initialize the DeutschJosza algorithm with the oracle and 2 qubits
bool result = dj.isFunctionConstant(); // Determine if the function is constant

The repository also contains tests for both Qubit and HermitianMatrix classes.


