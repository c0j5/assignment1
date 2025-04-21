#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Matrix create_matrix(size_t rows, size_t cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double*)malloc(rows * cols * sizeof(double));
    return m;
}

void free_matrix(Matrix* m) {
    free(m->data);
    m->data = NULL;
    m->rows = 0;
    m->cols = 0;
}

Matrix matrix_add(const Matrix* a, const Matrix* b) {
    assert(a->rows == b->rows && a->cols == b->cols);
    Matrix result = create_matrix(a->rows, a->cols);
    
    for (size_t i = 0; i < a->rows * a->cols; i++) {
        result.data[i] = a->data[i] + b->data[i];
    }
    
    return result;
}

Matrix matrix_multiply(const Matrix* a, const Matrix* b) {
    assert(a->cols == b->rows);
    Matrix result = create_matrix(a->rows, b->cols);
    
    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < b->cols; j++) {
            double sum = 0;
            for (size_t k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            result.data[i * result.cols + j] = sum;
        }
    }
    
    return result;
}

Matrix matrix_multiply_scalar(const Matrix* m, double scalar) {
    Matrix result = create_matrix(m->rows, m->cols);
    
    for (size_t i = 0; i < m->rows * m->cols; i++) {
        result.data[i] = m->data[i] * scalar;
    }
    
    return result;
}

Matrix matrix_transpose(const Matrix* m) {
    Matrix result = create_matrix(m->cols, m->rows);
    
    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            result.data[j * result.cols + i] = m->data[i * m->cols + j];
        }
    }
    
    return result;
}

void print_matrix(const Matrix* m) {
    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            printf("%6.2f ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}
