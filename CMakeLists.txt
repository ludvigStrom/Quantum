# CMakeList.txt : CMake project for Quantum, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Quantum "Quantum.cpp" "Quantum.h" "Qubit.cpp" "Qubit.h" "HermitianMatrix.h" "HermitianMatrix.cpp" "HermitianMatrixTests.cpp" "HermitianMatrixTests.h" "QubitTests.cpp" "QubitTests.h" "Oracle.cpp" "Oracle.h" "DeutschJosza.cpp" "DeutschJosza.h" "QuantumRegister.cpp" "QuantumRegister.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Quantum PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
