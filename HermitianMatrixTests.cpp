
#include "HermitianMatrix.h"
#include "HermitianMatrixTests.h"
#include <iostream>
#include <complex>
#include <cassert>

void testIsHermitian() {
    HermitianMatrix matrix({
    {std::complex<double>(1, 0), std::complex<double>(2, 3)},
    {std::complex<double>(2, -3), std::complex<double>(4, 0)}
        });

    assert(matrix.isHermitian() == true);
}

void testGetAdjoint() {
    HermitianMatrix matrix({
        {std::complex<double>(1, 0), std::complex<double>(2, 3)},
        {std::complex<double>(2, -3), std::complex<double>(4, 0)}
        });

    HermitianMatrix adjoint = matrix.getAdjoint();
    assert(adjoint.get(0, 0) == std::complex<double>(1, 0));
    assert(adjoint.get(0, 1) == std::complex<double>(2, 3));
    assert(adjoint.get(1, 0) == std::complex<double>(2, -3));
    assert(adjoint.get(1, 1) == std::complex<double>(4, 0));
}

void testMultiply() {
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
}