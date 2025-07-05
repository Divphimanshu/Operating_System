#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int absDiff(int a, int b) {
    return abs(a - b);
}

int main() {
    int n, head, total_seek = 0;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n], visited[n];
    printf("Enter disk request sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Seek Sequence:\n%d", head);

    for (int i = 0; i < n; i++) {
        int min = INT_MAX, index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && absDiff(head, request[j]) < min) {
                min = absDiff(head, request[j]);
                index = j;
            }
        }
        visited[index] = 1;
        total_seek += absDiff(head, request[index]);
        head = request[index];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    return 0;
}
