#include <stdio.h>

#define MAX_TASKS 10
#define MAX_TIME 400

typedef struct {
    int id;
    int Ci;  // Execution time (capacity)
    int Ti;  // Period
    int Di;  // Relative deadline
    int next_arrival;
    int remaining;
    int abs_deadline;
} Task;

int main() {
    int n, hyperperiod = 0;

    Task tasks[MAX_TASKS];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // Input
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;

        printf("\nTask %d\n", i + 1);
        printf("Execution Time (C): ");
        scanf("%d", &tasks[i].Ci);

        printf("Period (T): ");
        scanf("%d", &tasks[i].Ti);

        printf("Deadline (D): ");
        scanf("%d", &tasks[i].Di);

        tasks[i].next_arrival = 0;
        tasks[i].remaining = 0;
        tasks[i].abs_deadline = 0;

        if (tasks[i].Ti > hyperperiod)
            hyperperiod = tasks[i].Ti; // simple simulation limit
    }

    // Step 1: Utilization
    float U = 0;
    for (int i = 0; i < n; i++) {
        U += (float)tasks[i].Ci / tasks[i].Ti;
    }

    printf("\nCPU Utilization = %.2f\n", U);

    if (U > 1)
        printf("Not feasible (U > 1)\n");
    else
        printf("Feasible under EDF\n");

    printf("\n--- EDF Scheduling ---\n");

    // Time simulation
    for (int t = 0; t < MAX_TIME; t++) {

        // Job arrivals
        for (int i = 0; i < n; i++) {
            if (t == tasks[i].next_arrival) {
                tasks[i].remaining = tasks[i].Ci;
                tasks[i].abs_deadline = t + tasks[i].Di;
                tasks[i].next_arrival += tasks[i].Ti;
            }
        }

        // Select task with earliest deadline
        int selected = -1;
        int earliest_deadline = 1e9;

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                if (tasks[i].abs_deadline < earliest_deadline) {
                    earliest_deadline = tasks[i].abs_deadline;
                    selected = i;
                }
            }
        }

        // Execute
        if (selected == -1) {
            printf("Time %d: Idle\n", t);
        } else {
            printf("Time %d: Task %d running\n", t, tasks[selected].id);
            tasks[selected].remaining--;

            // Deadline miss check
            if (t > tasks[selected].abs_deadline) {
                printf("⚠ Deadline missed by Task %d\n", tasks[selected].id);
            }
        }
    }

    return 0;
}



