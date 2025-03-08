#include <stdio.h>

int main() {
    int n = 5; // Number of rows (fixed to match the pattern)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) { // Width should be 2*n - 1 for proper alignment
            if (i == 0 || i == n - 1) {
                // Print alternating '*' and '#' for the first and last rows
                printf("%c", (j % 2 == 0) ? '*' : '#');
            } else if (j == 0) {
                printf("#"); // First column of middle rows
            } else if (j == 2 * n - 2) {
                printf("*"); // Last column of middle rows
            } else {
                printf(" "); // Spaces in between
            }
        }
        printf("\n");
    }

    return 0;
}
