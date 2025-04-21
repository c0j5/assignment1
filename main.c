#include "matrix.h"
#include <stdio.h>

int main() {
    // Initialize matrices A, B, C
    Matrix A = create_matrix(2, 2);
    A.data[0] = 6; A.data[1] = 4;
    A.data[2] = 8; A.data[3] = 3;
    
    Matrix B = create_matrix(2, 3);
    B.data[0] = 1; B.data[1] = 2; B.data[2] = 3;
    B.data[3] = 4; B.data[4] = 5; B.data[5] = 6;
    
    Matrix C = create_matrix(2, 3);
    C.data[0] = 2; C.data[1] = 4; C.data[2] = 6;
    C.data[3] = 1; C.data[4] = 3; C.data[5] = 5;
    
    // Compute D = A + (3 * B) × C^T
    Matrix threeB = matrix_multiply_scalar(&B, 3);
    Matrix CT = matrix_transpose(&C);
    Matrix product = matrix_multiply(&threeB, &CT);
    Matrix D = matrix_add(&A, &product);
    
    // Print results
    printf("Matrix A:\n");
    print_matrix(&A);
    
    printf("\nMatrix B:\n");
    print_matrix(&B);
    
    printf("\nMatrix C:\n");
    print_matrix(&C);
    
    printf("\nMatrix D = A + (3 * B) × C^T:\n");
    print_matrix(&D);
    
    // Clean up
    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);
    free_matrix(&threeB);
    free_matrix(&CT);
    free_matrix(&product);
    free_matrix(&D);
    
    return 0;
}
