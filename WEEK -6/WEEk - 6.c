#include <stdio.h>
#include <math.h>

#define MAX 20

typedef struct {
    int id;
    float Ci;  // Execution time
    float Ti;  // Period
    float priority;
} Task;

// Function to sort tasks by period (ascending)
void sortByPeriod(Task tasks[], int n) {
    Task temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].Ti > tasks[j].Ti) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    Task tasks[MAX];
    float U = 0.0, bound;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // Input task details
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("\nTask %d:\n", i + 1);
        printf("Execution Time (Ci): ");
        scanf("%f", &tasks[i].Ci);
        printf("Period (Ti): ");
        scanf("%f", &tasks[i].Ti);

        U += (tasks[i].Ci / tasks[i].Ti);
    }

    printf("\nCPU Utilization (U) = %.4f\n", U);
    printf("RMS Bound = %.4f\n", bound);

    // Check schedulability
    if (U <= bound)
        printf("Schedulable using RMS\n");
    else
        printf("Not guaranteed schedulable (need further analysis)\n");

    // Assign priorities (shorter period = higher priority)
    sortByPeriod(tasks, n);

    printf("\nTask Priorities (1 = Highest):\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d → Priority %d (Ti = %.2f)\n",
               tasks[i].id, i + 1, tasks[i].Ti);
    }

    return 0;
}
