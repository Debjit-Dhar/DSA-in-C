#include <stdio.h>

#define ROWS 3
#define COLS 4

void printMatrix(float matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void reduceMatrix(float matrix[ROWS][COLS]) {
    int lead = 0;
    for (int r = 0; r < ROWS; r++) {
        if (lead >= COLS) {
            return;
        }
        int i = r;
        while (matrix[i][lead] == 0) {
            i++;
            if (i == ROWS) {
                i = r;
                lead++;
                if (lead == COLS) {
                    return;
                }
            }
        }
        float tmp[COLS];
        for (int j = 0; j < COLS; j++) {
            tmp[j] = matrix[r][j];
            matrix[r][j] = matrix[i][j];
            matrix[i][j] = tmp[j];
        }
        float lv = matrix[r][lead];
        for (int j = 0; j < COLS; j++) {
            matrix[r][j] /= lv;
        }
        for (int j = 0; j < ROWS; j++) {
            if (j != r) {
                float lv2 = matrix[j][lead];
                for (int k = 0; k < COLS; k++) {
                    matrix[j][k] -= lv2 * matrix[r][k];
                }
            }
        }
        lead++;
    }
}

int main() {
    float matrix[ROWS][COLS] = {
        {0, 1, 1, 2},
        {3, 1, 5, 4},
        {-2, 7, 3, 8}
    };
    printf("Original matrix:\n");
    printMatrix(matrix);
    reduceMatrix(matrix);
    printf("Reduced row echelon form:\n");
    printMatrix(matrix);
    return 0;
}