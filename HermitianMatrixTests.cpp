
#include "HermitianMatrix.h"
#include "HermitianMatrixTests.h"
#include <iostream>
#include <complex>
#include <cassert>

void testIsHermitian() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testIsHermitian..." << std::endl;

    HermitianMatrix matrix({
        {std::complex<double>(1, 0), std::complex<double>(2, 3)},
        {std::complex<double>(2, -3), std::complex<double>(4, 0)}
        });

    bool isHermitian = matrix.isHermitian();
    std::cout << "Matrix is " << (isHermitian ? "" : "not ") << "Hermitian." << std::endl;
    assert(isHermitian == true);

    std::cout << "testIsHermitian passed!" << std::endl;
}

void testGetAdjoint() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testGetAdjoint..." << std::endl;

    HermitianMatrix matrix({
        {std::complex<double>(1, 0), std::complex<double>(2, 3)},
        {std::complex<double>(2, -3), std::complex<double>(4, 0)}
        });

    HermitianMatrix adjoint = matrix.getAdjoint();
    std::cout << "Adjoint matrix obtained." << std::endl;
    std::cout << "Adjoint(0, 0): " << adjoint.get(0, 0) << std::endl;
    std::cout << "Adjoint(0, 1): " << adjoint.get(0, 1) << std::endl;
    std::cout << "Adjoint(1, 0): " << adjoint.get(1, 0) << std::endl;
    std::cout << "Adjoint(1, 1): " << adjoint.get(1, 1) << std::endl;

    assert(adjoint.get(0, 0) == std::complex<double>(1, 0));
    assert(adjoint.get(0, 1) == std::complex<double>(2, 3));
    assert(adjoint.get(1, 0) == std::complex<double>(2, -3));
    assert(adjoint.get(1, 1) == std::complex<double>(4, 0));

    std::cout << "testGetAdjoint passed!" << std::endl;
}

void testMultiply() {
    std::cout << "\n___________________________" << std::endl;
    std::cout << "Starting testMultiply..." << std::endl;

    HermitianMatrix matrix({
        {std::complex<double>(1, 0), std::complex<double>(2, 3)},
        {std::complex<double>(2, -3), std::complex<double>(4, 0)}
        });

    std::vector<std::complex<double>> vector = { std::complex<double>(1, 0), std::complex<double>(0, 1) };
    std::vector<std::complex<double>> result = matrix.multiply(vector);

    // Print the actual result before the assertion
    std::cout << "Actual result[0]: " << result[0] << std::endl;
    std::cout << "Actual result[1]: " << result[1] << std::endl;

    assert(result[0] == std::complex<double>(-2, 2));  // Corrected the expected value
    assert(result[1] == std::complex<double>(2, 1));

    std::cout << "testMultiply passed!" << std::endl;
}
