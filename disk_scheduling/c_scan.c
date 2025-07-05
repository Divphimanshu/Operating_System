#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, head, size;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter disk request sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    request[n++] = head;
    request[n++] = 0;
    request[n++] = size - 1;

    qsort(request, n, sizeof(int), compare);

    int total = 0, i, pos;
    for (i = 0; i < n; i++) {
        if (request[i] == head) {
            pos = i;
            break;
        }
    }

    printf("Seek Sequence:\n");

    for (i = pos; i < n - 1; i++) {
        printf("%d -> ", request[i]);
        total += abs(request[i + 1] - request[i]);
    }

    total += abs(request[n - 1] - 0); // jump to start
    printf("%d -> 0", request[n - 1]);

    for (i = 0; i < pos; i++) {
        printf(" -> %d", request[i]);
        total += abs(request[i] - (i == 0 ? 0 : request[i - 1]));
    }

    printf("\nTotal Seek Time = %d\n", total);
    return 0;
}
