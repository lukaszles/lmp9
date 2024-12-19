#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r!= b->r || b->c != 1) {
        return 1; // Niezgodne wymiary macierzy
    }
    
    int n = mat->r;

    for (int k = 0; k < n; ++k) {
        if (fabs(mat->data[k][k]) == 0) {
            return 1; // Dzielenie przez zero (macierz osobliwa)
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