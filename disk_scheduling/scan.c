#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, head, size, i, j, direction;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter disk request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    request[n++] = head;
    request[n++] = 0;
    request[n++] = size - 1;

    qsort(request, n, sizeof(int), compare);

    int pos;
    for (i = 0; i < n; i++) {
        if (request[i] == head) {
            pos = i;
            break;
        }
    }

    int total = 0;
    printf("Seek Sequence:\n");

    if (direction == 1) {
        for (i = pos; i < n - 1; i++) {
            printf("%d -> ", request[i]);
            total += abs(request[i + 1] - request[i]);
        }
        for (i = pos - 1; i >= 0; i--) {
            printf("%d", request[i]);
            if (i != 0) printf(" -> ");
            total += abs(request[i + 1] - request[i]);
        }
    } else {
        for (i = pos; i > 0; i--) {
            printf("%d -> ", request[i]);
            total += abs(request[i] - request[i - 1]);
        }
        for (i = pos + 1; i < n; i++) {
            printf("%d", request[i]);
            if (i != n - 1) printf(" -> ");
            total += abs(request[i] - request[i - 1]);
        }
    }

    printf("\nTotal Seek Time = %d\n", total);
    return 0;
}
