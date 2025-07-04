#include <stdio.h>
#include <stdbool.h>

#define MAX_P 10 // Max number of processes
#define MAX_R 10 // Max number of resources

int main() {
    int n, m, i, j, k;
    int alloc[MAX_P][MAX_R], max[MAX_P][MAX_R], avail[MAX_R];
    int need[MAX_P][MAX_R];
    int finish[MAX_P] = {0}, safeSeq[MAX_P];
    int count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter the available resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate the need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Safety algorithm
    while (count < n) {
        bool found = false;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                bool possible = true;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    for (k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("\nThe system is in an UNSAFE state! Deadlock may occur.\n");
            return 1;
        }
    }

    printf("\nThe system is in a SAFE state.\nSafe sequence: ");
    for (i = 0; i < n; i++) {
        printf("P[%d] ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}
