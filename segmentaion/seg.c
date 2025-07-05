#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEGMENTS 10

struct Segment {
    char name[20];
    int base;
    int limit;
};

void displaySegments(struct Segment segs[], int n) {
    printf("\nSegment Table:\n");
    printf("Name\tBase\tLimit\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\n", segs[i].name, segs[i].base, segs[i].limit);
    }
}

void logicalToPhysical(struct Segment segs[], int n) {
    char name[20];
    int offset;
    printf("\nEnter Segment Name: ");
    scanf("%s", name);
    printf("Enter Offset: ");
    scanf("%d", &offset);

    for (int i = 0; i < n; i++) {
        if (strcmp(segs[i].name, name) == 0) {
            if (offset < segs[i].limit) {
                int physical = segs[i].base + offset;
                printf("Physical Address: %d\n", physical);
            } else {
                printf("Error: Offset exceeds limit of segment.\n");
            }
            return;
        }
    }
    printf("Error: Segment not found.\n");
}

int main() {
    int n;
    struct Segment segs[MAX_SEGMENTS];

    printf("Enter number of segments: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for segment %d\n", i + 1);
        printf("Segment Name: ");
        scanf("%s", segs[i].name);
        printf("Base Address: ");
        scanf("%d", &segs[i].base);
        printf("Limit: ");
        scanf("%d", &segs[i].limit);
    }

    displaySegments(segs, n);

    char choice;
    do {
        logicalToPhysical(segs, n);
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
