#pragma once

#include <vector>
#include <complex>
#include <iostream>

class HermitianMatrix {
private:
    std::vector<std::vector<std::complex<double>>> data;

public:
    HermitianMatrix(const std::vector<std::vector<std::complex<double>>>& matrix);

    void setElement(size_t row, size_t col, std::complex<double> value);
    std::complex<double> getElement(size_t row, size_t col) const;
    bool isHermitian() const;
    void printMatrix() const;
    HermitianMatrix getAdjoint() const;
    std::complex<double> get(size_t row, size_t col) const;
    std::vector<std::complex<double>> multiply(const std::vector<std::complex<double>>& vec) const;

};
