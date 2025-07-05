#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[50], frames[10], time[10], n, f, count = 0, faults = 0;
    int i, j, pos, flag1, flag2;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < n; i++) {
        flag1 = flag2 = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                count++;
                time[j] = count;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (!flag1) {
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    count++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = count;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (!flag2) {
            pos = findLRU(time, f);
            count++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = count;
        }

        printf("Frames: ");
        for (j = 0; j < f; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}
