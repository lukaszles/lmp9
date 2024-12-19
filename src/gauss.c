#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap_rows(Matrix *mat, Matrix *b, int r1, int r2) {
    for (int j = 0; j < mat->c; ++j) {
        double temp = mat->data[r1][j];
        mat->data[r1][j] = mat->data[r2][j];
        mat->data[r2][j] = temp;
    }
    double temp = b->data[r1][0];
    b->data[r1][0] = b->data[r2][0];
    b->data[r2][0] = temp;
}

int eliminate(Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r != b->r || b->c != 1) {
        return 1; // Niezgodne wymiary macierzy
    }

    int n = mat->r;

    for (int k = 0; k < n; ++k) {
        int max_row = k;
        for (int i = k + 1; i < n; ++i) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[max_row][k])) {
                max_row = i;
            }
        }

        if (fabs(mat->data[max_row][k]) == 0) {
            return 1; // Dzielenie przez zero
        }

        if (max_row != k) {
            swap_rows(mat, b, k, max_row);
        }

        for (int i = k + 1; i < n; ++i) {
            double factor = mat->data[i][k] / mat->data[k][k];
            for (int j = k; j < n; ++j) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0; // Eliminacja zakończona sukcesem
}