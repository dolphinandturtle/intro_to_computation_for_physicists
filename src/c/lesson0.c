#include <stdio.h>

void row_scale(int n, float R[n], float fac) {
    for (int j = 0; j < n; j = j + 1) {
        R[j] = fac * R[j];
    }
    return;
}

void row_add(int n, float R0[n], float R1[n], float fac) {
    for (int j = 0; j < n; j = j + 1) {
        R0[j] = R0[j] + fac * R1[j];
    }
    return;
}

void row_swap(int n, float R0[n], float R1[n]) {
    float tmp = 0.0;
    for (int j = 0; j < n; j = j + 1) {
        tmp = R0[j];
        R0[j] = R1[j];
        R1[j] = tmp;
    }
    return;
}

void matrix_print(int m, int n, float M[m][n]) {
    for (int i = 0; i < m; i = i + 1) {
        printf("[");
        for (int j = 0; j < n - 1; j = j + 1) {
            printf("%.2f ", M[i][j]);
        }
        printf("%.2f]\n", M[i][n-1]);
    }
    printf("\n");
    return;
}

void row_reduction(const int m, const int n, float M[m][n]) {
    for (
        // Offset row, offset column and pivot row.
        int oi = 0, oj = 0, pi = oi;
        (oi < m && oj < n);
        oi++, oj++, pi = oi
    ){
        // Find pivot row.
        while (M[pi][oj] == 0.0) {
            if (pi < m - 1) {
                pi++;
            }
            else if (oj < n - 1) {
                pi = oi;
                oj++;
            }
            else {
                return;
            }
        }
        // Normalize pivot row.
        row_scale(n - oj, M[pi] + oj, 1/M[pi][oj]);
        // Clip offset column using pivot row as a mask.
        for (int i = pi + 1; i < m; i++) {
            row_add(n - oj, M[i] + oj, M[pi] + oj, -M[i][oj]);
        }
        // Swap pivot row with offset row.
        if (pi != oi) {
            row_swap(n - oj, M[oi] + oj, M[pi] + oj);
        }
    }
    return;
    /*
    [NOTES]
    --------------------------------------
    Everything preceding the offset during
    matrix triangularization is such that:
    1) It doesn't change further steps.
    2) It isn't changed by further steps.
    --------------------------------------
    therefore it is completely ignored by
    offsetting the matrices index.
    --------------------------------------
    */
}

int main(void) {
    float M[3][4] = {
        {0, 2, 3, 4},
        {1, 7, 7, 7},
        {9, 8, 7, 0}
    };
    row_reduction(3, 4, M);
    matrix_print(3, 4, M);
    return 0;
}
