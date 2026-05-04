#include <stdio.h>

#define MAX 20
#define TIME_QUANTUM 10   // base quantum

typedef struct {
    int id;
    int arrival;
    int burst;
    int remaining;
    int weight;
    int completed;
} Process;

int main() {
    int n;
    Process p[MAX];
    int total_weight = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("\nProcess %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Execution Time: ");
        scanf("%d", &p[i].burst);

        printf("Weight: ");
        scanf("%d", &p[i].weight);

        p[i].remaining = p[i].burst;
        p[i].completed = 0;

        total_weight += p[i].weight;
    }

    int time = 0, completed = 0;

    printf("\n--- Proportional Share Scheduling ---\n");

    while (completed < n) {

        int progress = 0; // to detect idle time

        for (int i = 0; i < n; i++) {

            if (p[i].arrival <= time && p[i].completed == 0) {

                // Step 8: calculate proportional time slice
                int time_slice = (p[i].weight * TIME_QUANTUM) / total_weight;

                // Ensure at least 1 unit runs
                if (time_slice <= 0)
                    time_slice = 1;

                if (p[i].remaining < time_slice)
                    time_slice = p[i].remaining;

                printf("Time %d to %d: P%d\n", time, time + time_slice, p[i].id);

                time += time_slice;
                p[i].remaining -= time_slice;
                progress = 1;

                // Completion check
                if (p[i].remaining <= 0) {
                    p[i].completed = 1;
                    completed++;
                    total_weight -= p[i].weight;

                    printf("P%d completed at time %d\n", p[i].id, time);
                }
            }
        }

        // If no process was ready
        if (!progress) {
            printf("Time %d: Idle\n", time);
            time++;
        }
    }

    return 0;
}
