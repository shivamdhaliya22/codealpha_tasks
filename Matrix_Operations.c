#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    int i, j;

    printf("Enter elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrix Multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;

            for (k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matrix Transpose
void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX],
                     int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }
}

int main() {

    int A[MAX][MAX], B[MAX][MAX];
    int C[MAX][MAX], T[MAX][MAX];

    int r1, c1, r2, c2;

    // Input dimensions
    printf("Enter rows & columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows & columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Input matrices
    printf("\nMatrix A:\n");
    inputMatrix(A, r1, c1);

    printf("\nMatrix B:\n");
    inputMatrix(B, r2, c2);

    // Display matrices
    printf("\nMatrix A:\n");
    displayMatrix(A, r1, c1);

    printf("\nMatrix B:\n");
    displayMatrix(B, r2, c2);

    // Addition
    if (r1 == r2 && c1 == c2) {

        addMatrix(A, B, C, r1, c1);

        printf("\nMatrix Addition (A + B):\n");
        displayMatrix(C, r1, c1);

    } else {
        printf("\nMatrix Addition is not possible.\n");
    }

    // Multiplication
    if (c1 == r2) {

        multiplyMatrix(A, B, C, r1, c1, c2);

        printf("\nMatrix Multiplication (A * B):\n");
        displayMatrix(C, r1, c2);

    } else {
        printf("\nMatrix Multiplication is not possible.\n");
    }

    // Transpose
    transposeMatrix(A, T, r1, c1);

    printf("\nTranspose of Matrix A:\n");
    displayMatrix(T, c1, r1);

    return 0;
}