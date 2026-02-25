#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int inputMatr(int **matrix, int rows, int cols);
void output(int **matrix, int rows, int cols);
void staticMatr(int rows, int cols);
void menu(int choise, int rows, int cols);

int main() {
    int choise;
    if (scanf("%d", &choise) == 1 && choise >= 1 && choise <= 4) {
        int rows, cols;
        if (scanf("%d%d", &rows, &cols) == 2 && rows > 0 && rows <= NMAX && cols > 0 && cols <= NMAX) {
            menu(choise, rows, cols);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}

void output(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (i > 0) printf("\n");
        for (int j = 0; j < cols; j++) {
            if (j > 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
    }
}

void staticMatr(int rows, int cols) {
    int matrix[rows][cols], flag = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                flag = 0;
                break;
            }
        }
    }
    if (flag) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    } else
        printf("n/a");
}

void menu(int choise, int rows, int cols) {
    switch (choise) {
        case 1: {
            staticMatr(rows, cols);
            break;
        }
        case 2: {
            int **matrix = (int **)calloc(rows, sizeof(int *));
            for (int i = 0; i < rows; i++) {
                matrix[i] = calloc(cols, sizeof(int));
            }
            if (inputMatr(matrix, rows, cols)) {
                output(matrix, rows, cols);
            } else
                printf("n/a");
            for (int i = 0; i < rows; i++) {
                free(matrix[i]);
            }
            free(matrix);
            matrix = NULL;
            break;
        }
        case 3: {
            int **matrix = (int **)malloc(rows * sizeof(int *));
            int *arr = (int *)malloc(rows * cols * sizeof(int));
            for (int i = 0; i < rows; i++) {
                matrix[i] = &arr[i * cols];
            }
            if (inputMatr(matrix, rows, cols)) {
                output(matrix, rows, cols);
            } else
                printf("n/a");
            free(matrix);
            free(arr);
            matrix = NULL;
            break;
        }
        case 4: {
            int **matrix = malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
            for (int i = 0; i < rows; i++) {
                matrix[i] = (int *)(matrix + rows) + (i * cols);
            }
            if (inputMatr(matrix, rows, cols)) {
                output(matrix, rows, cols);
            } else
                printf("n/a");
            free(matrix);
            matrix = NULL;
            break;
        }
    }
}

int inputMatr(int **matrix, int rows, int cols) {
    int flag = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}
