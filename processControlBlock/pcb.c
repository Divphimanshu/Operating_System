#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 5

// Process States
typedef enum { NEW, READY, RUNNING, WAITING, TERMINATED } State;

// Convert enum to string
const char* getStateName(State state) {
    switch(state) {
        case NEW: return "NEW";
        case READY: return "READY";
        case RUNNING: return "RUNNING";
        case WAITING: return "WAITING";
        case TERMINATED: return "TERMINATED";
        default: return "UNKNOWN";
    }
}

// Process Control Block structure
typedef struct {
    int pid;
    char processName[20];
    int priority;
    State state;
    int pc;   // Program Counter
    int memory; // Memory used
} PCB;

// Simulate context switch
void contextSwitch(PCB* from, PCB* to) {
    printf("\nContext Switching...\n");
    if (from != NULL) {
        from->state = READY;
        printf("Saving state of Process %s (PID: %d)\n", from->processName, from->pid);
    }
    to->state = RUNNING;
    printf("Loading state of Process %s (PID: %d)\n", to->processName, to->pid);
}

int main() {
    PCB processes[MAX_PROCESSES];

    // Create processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i + 1;
        sprintf(processes[i].processName, "Process%d", i + 1);
        processes[i].priority = rand() % 10;
        processes[i].state = NEW;
        processes[i].pc = 1000 + i * 100;
        processes[i].memory = 1024 + rand() % 2048;
    }

    // Transition to READY
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].state = READY;
    }

    // Simulate process scheduling and context switching
    PCB* current = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        contextSwitch(current, &processes[i]);
        current = &processes[i];

        // Simulate execution
        printf("Executing %s...\n", current->processName);
        current->pc += 100;

        // After execution, mark process as TERMINATED
        current->state = TERMINATED;
        printf("%s completed execution.\n", current->processName);
    }

    // Display final process table
    printf("\nFinal Process Table:\n");
    printf("PID\tName\t\tPriority\tState\t\tPC\tMemory\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t%s\t\t%d\t\t%s\t%d\t%d\n",
               processes[i].pid,
               processes[i].processName,
               processes[i].priority,
               getStateName(processes[i].state),
               processes[i].pc,
               processes[i].memory);
    }

    return 0;
}
