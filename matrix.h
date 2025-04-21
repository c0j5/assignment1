#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

typedef struct {
    size_t rows;
    size_t cols;
    double* data;
} Matrix;

Matrix create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* m);
Matrix matrix_add(const Matrix* a, const Matrix* b);
Matrix matrix_multiply(const Matrix* a, const Matrix* b);
Matrix matrix_multiply_scalar(const Matrix* m, double scalar);
Matrix matrix_transpose(const Matrix* m);
void print_matrix(const Matrix* m);

#endif
