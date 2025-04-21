#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <cstddef>

class Matrix {
private:
    size_t rows_;
    size_t cols_;
    std::vector<std::vector<double>> data_;
    
public:
    Matrix(size_t rows, size_t cols);
    Matrix(size_t rows, size_t cols, const std::vector<std::vector<double>>& data);
    
    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
    
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix transpose() const;
    
    void print() const;
    
    static Matrix multiply_scalar(const Matrix& m, double scalar);
};

#endif
