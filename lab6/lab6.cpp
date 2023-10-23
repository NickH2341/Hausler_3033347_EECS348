#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    readMatrixFromFile(matrixA, matrixB, size, "matrix_input.txt");

    std::cout << "Nicholas Hausler" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);

    addMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);

    multiplyMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);

    subtractMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size);

    return 0;
}

void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrixA[i][j];
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrixB[i][j];
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        exit(1);
    }
}


void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
