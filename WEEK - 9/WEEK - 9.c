#include <stdio.h>

struct Process
{
    int id;
    int bt;     // Burst Time
    int share;  // Share (weight)
    int ct;     // Completion Time
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
};

int main()
{
    int n, i, time = 0, total_share = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for (i = 0; i < n; i++)
    {
        p[i].id = i;
        printf("\nProcess %d:\n", i);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Share (for Proportional): ");
        scanf("%d", &p[i].share);

        total_share += p[i].share;
    }

    printf("\n===== Proportional Share Scheduling =====\n");
    printf("ID\tBT\tShare\tCT\tWT\tTAT\n");

    int remaining[n];
    for (i = 0; i < n; i++)
        remaining[i] = p[i].bt;

    // Run until all processes finish
    while (1)
    {
        int done = 1;

        for (i = 0; i < n; i++)
        {
            if (remaining[i] > 0)
            {
                done = 0;

                // Allocate time slice proportional to share
                int slice = (p[i].share * 1); // base quantum = 1

                if (remaining[i] < slice)
                    slice = remaining[i];

                remaining[i] -= slice;
                time += slice;

                if (remaining[i] == 0)
                {
                    p[i].ct = time;
                    p[i].tat = p[i].ct;
                    p[i].wt = p[i].tat - p[i].bt;
                }
            }
        }

        if (done)
            break;
    }

    // Output
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].bt,
               p[i].share,
               p[i].ct,
               p[i].wt,
               p[i].tat);
    }

    return 0;
}
