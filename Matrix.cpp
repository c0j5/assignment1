#include "Matrix.hpp"
#include <stdexcept>
#include <iostream>

Matrix::Matrix(size_t rows, size_t cols) 
    : rows_(rows), cols_(cols), data_(rows, std::vector<double>(cols, 0)) {}

Matrix::Matrix(size_t rows, size_t cols, const std::vector<std::vector<double>>& data)
    : rows_(rows), cols_(cols), data_(data) {
    if (data.size() != rows || (rows > 0 && data[0].size() != cols)) {
        throw std::invalid_argument("Invalid dimensions for matrix data");
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    
    Matrix result(rows_, cols_);
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            result.data_[i][j] = data_[i][j] + other.data_[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols_ != other.rows_) {
        throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
    }
    
    Matrix result(rows_, other.cols_);
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < other.cols_; j++) {
            double sum = 0;
            for (size_t k = 0; k < cols_; k++) {
                sum += data_[i][k] * other.data_[k][j];
            }
            result.data_[i][j] = sum;
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    return multiply_scalar(*this, scalar);
}

Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            result.data_[j][i] = data_[i][j];
        }
    }
    return result;
}

void Matrix::print() const {
    for (const auto& row : data_) {
        for (double val : row) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::multiply_scalar(const Matrix& m, double scalar) {
    Matrix result(m.rows_, m.cols_);
    for (size_t i = 0; i < m.rows_; i++) {
        for (size_t j = 0; j < m.cols_; j++) {
            result.data_[i][j] = m.data_[i][j] * scalar;
        }
    }
    return result;
}
