#include "HermitianMatrix.h"

HermitianMatrix::HermitianMatrix(const std::vector<std::vector<std::complex<double>>>& matrix) {
    data = matrix;
}

void HermitianMatrix::setElement(size_t row, size_t col, std::complex<double> value) {
    data[row][col] = value;
    data[col][row] = std::conj(value);  // Ensure the matrix remains Hermitian
}

std::complex<double> HermitianMatrix::getElement(size_t row, size_t col) const {
    return data[row][col];
}

bool HermitianMatrix::isHermitian() const {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            if (data[i][j] != std::conj(data[j][i])) {
                return false;
            }
        }
    }
    return true;
}

void HermitianMatrix::printMatrix() const {
    for (const auto& row : data) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

HermitianMatrix HermitianMatrix::getAdjoint() const {
    size_t size = data.size();
    std::vector<std::vector<std::complex<double>>> adjointData(size, std::vector<std::complex<double>>(size, 0.0));

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            adjointData[i][j] = std::conj(data[j][i]);
        }
    }

    HermitianMatrix adjoint(adjointData);
    return adjoint;
}

std::complex<double> HermitianMatrix::get(size_t row, size_t col) const {
    return data[row][col];
}

std::vector<std::complex<double>> HermitianMatrix::multiply(const std::vector<std::complex<double>>& vec) const {
    size_t size = data.size();
    std::vector<std::complex<double>> result(size, 0.0);

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result[i] += data[i][j] * vec[j];
        }
    }

    return result;
}