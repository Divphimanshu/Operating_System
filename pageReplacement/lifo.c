#include <stdio.h>

int main() {
    int pages[50], frames[10], n, f, i, top = -1, j, k, flag, page_faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++) {
        flag = 0;

        for (j = 0; j <= top; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            if (top < f - 1) {
                frames[++top] = pages[i];
            } else {
                frames[top] = pages[i];  // Replace the most recently added (LIFO)
            }
            page_faults++;
        }

        printf("Frames: ");
        for (k = 0; k <= top; k++) {
            if (frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
