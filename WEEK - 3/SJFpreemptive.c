#include <stdio.h>

int main()
{
    int n,i,time=0,complete=0;
    int at[20],bt[20],rt[20],ct[20],wt[20],tat[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("AT P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("BT P%d: ",i+1);
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
    }

    while(complete<n)
    {
        int idx=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(idx==-1 || rt[i]<rt[idx])
                    idx=i;
            }
        }

        if(idx==-1)
        {
            time++;
            continue;
        }

        rt[idx]--;
        time++;

        if(rt[idx]==0)
        {
            complete++;

            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
        }
    }

      printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
}
  float awt = 0, atat = 0;
    for (i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turn-Around Time: %.2f\n", atat / n);
}
