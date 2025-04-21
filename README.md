# assignment1
# Matrix Library Implementation

## AUTHORING
- Christian Jones (UMBC, CMSC 313 MonWed 8:30)

## PURPOSE OF SOFTWARE
This project implements a matrix library in both C (C99 standard) and C++ that can perform basic matrix operations including addition, multiplication, scalar multiplication, and transposition. The library is used to compute the matrix equation: D = A + (3 * B) × C^T.

## FILES
- `c_version/`
  - `matrix.h` - Header file for C matrix library
  - `matrix.c` - Implementation of C matrix functions
  - `main.c` - Test program demonstrating matrix operations
  - `Makefile` - Build instructions for C version
- `cpp_version/`
  - `Matrix.hpp` - Header file for C++ Matrix class
  - `Matrix.cpp` - Implementation of Matrix class methods
  - `main.cpp` - Test program demonstrating matrix operations
  - `Makefile` - Build instructions for C++ version
- `README.md` - This documentation file
- `screenshot.png` - Screenshot of program execution

## BUILD INSTRUCTIONS
### C Version
1. Navigate to `c_version/` directory
2. Run `make` to build the program
3. Execute with `./matrix_test`

### C++ Version
1. Navigate to `cpp_version/` directory
2. Run `make` to build the program
3. Execute with `./matrix_test_cpp`

## TESTING METHODOLOGY
The test programs in both versions:
1. Create matrices A, B, and C with the specified values
2. Compute the equation D = A + (3 * B) × C^T
3. Print all matrices to verify correct calculations

The expected output should show:
- Original matrices A, B, and C
- The resulting matrix D with correct computed values

## ADDITIONAL INFORMATION
- The C version follows C99 standard and uses a simple struct-based approach
- The C++ version uses object-oriented design with operator overloading
- Both implementations include bounds checking and error handling
