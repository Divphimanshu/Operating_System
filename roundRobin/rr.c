#include <stdio.h>

int main() {
    int i, n, time = 0, tq, remain, flag = 0;
    int at[10], bt[10], rt[10];
    int wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    for(time = 0, i = 0; remain != 0;) {
        if(rt[i] > 0 && at[i] <= time) {
            if(rt[i] <= tq) {
                time += rt[i];
                rt[i] = 0;
                flag = 1;
            } else {
                rt[i] -= tq;
                time += tq;
            }

            if(rt[i] == 0 && flag == 1) {
                remain--;
                printf("P[%d]\t%d\t\t%d\n", i + 1, time - at[i], time - at[i] - bt[i]);
                wt += time - at[i] - bt[i];
                tat += time - at[i];
                flag = 0;
            }
        }

        // Move to next process
        i = (i + 1) % n;
    }

    printf("\nAverage Waiting Time: %.2f", (float)wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)tat / n);

    return 0;
}
