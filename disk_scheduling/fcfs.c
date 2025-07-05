#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek = 0;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter disk request sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Seek Sequence:\n%d", head);
    for (int i = 0; i < n; i++) {
        seek += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);
    return 0;
}
