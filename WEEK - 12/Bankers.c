#include <stdio.h>

int main()
{
    int n, m, i, j, k, pid, count = 0, found;

    printf("Enter number of processes -- ");
    scanf("%d", &n);

    printf("Enter number of resources -- ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], req[m], work[m], finish[n], safe[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details for P%d\n", i);

        printf("Enter allocation -- ");
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

        printf("Enter Max        -- ");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nEnter Available Resources -- ");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    printf("\nEnter New Request Details --\n");

    printf("Enter pid -- ");
    scanf("%d", &pid);

    printf("Enter Request for Resources -- ");
    for(i = 0; i < m; i++)
        scanf("%d", &req[i]);

    for(i = 0; i < m; i++)
    {
        if(req[i] > need[pid][i] || req[i] > avail[i])
        {
            printf("\nRequest cannot be granted\n");
            return 0;
        }

        avail[i] -= req[i];
        alloc[pid][i] += req[i];
        need[pid][i] -= req[i];

        work[i] = avail[i];
    }

    for(i = 0; i < n; i++)
        finish[i] = 0;

    while(count < n)
    {
        found = 0;

        for(i = 0; i < n; i++)
        {
            if(!finish[i])
            {
                for(j = 0; j < m; j++)
                    if(need[i][j] > work[j])
                        break;

                if(j == m)
                {
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    printf("P%d is visited(", i);

                    for(k = 0; k < m; k++)
                        printf("%d ", work[k]);

                    printf(")\n");

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found)
            break;
    }

    if(count == n)
    {
        printf("\nSYSTEM IS IN SAFE STATE\n");
        printf("The Safe Sequence is -- (");

        for(i = 0; i < n; i++)
            printf("P%d ", safe[i]);

        printf(")\n");
    }
    else
        printf("\nSYSTEM IS NOT IN SAFE STATE\n");
    // Display Table
    printf("\n\nProcess\tAllocation\tMax\t\tNeed\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t", i);

        for(j = 0; j < m; j++)
            printf("%d ", alloc[i][j]);

        printf("\t\t");

        for(j = 0; j < m; j++)
            printf("%d ", max[i][j]);

        printf("\t\t");

        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }

    return 0;
}

