#include "Matrix.hpp"
#include <iostream>

int main() {
    // Initialize matrices A, B, C
    Matrix A(2, 2, {{6, 4}, {8, 3}});
    Matrix B(2, 3, {{1, 2, 3}, {4, 5, 6}});
    Matrix C(2, 3, {{2, 4, 6}, {1, 3, 5}});
    
    // Compute D = A + (3 * B) × C^T
    Matrix threeB = B * 3;
    Matrix CT = C.transpose();
    Matrix product = threeB * CT;
    Matrix D = A + product;
    
    // Print results
    std::cout << "Matrix A:" << std::endl;
    A.print();
    
    std::cout << "\nMatrix B:" << std::endl;
    B.print();
    
    std::cout << "\nMatrix C:" << std::endl;
    C.print();
    
    std::cout << "\nMatrix D = A + (3 * B) × C^T:" << std::endl;
    D.print();
    
    return 0;
}
