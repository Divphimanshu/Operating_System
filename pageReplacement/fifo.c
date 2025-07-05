#include <stdio.h>

int main() {
    int pages[50], frames[10], n, f, i, j = 0, k, flag, page_faults = 0;
    
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

        for (k = 0; k < f; k++) {
            if (frames[k] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            frames[j] = pages[i];
            j = (j + 1) % f;
            page_faults++;
        }

        printf("Frames: ");
        for (k = 0; k < f; k++) {
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
