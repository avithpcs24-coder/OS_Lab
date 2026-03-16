#include<stdio.h>
void main()
{
    int n,i,j;
    int id[10],at[10],bt[10],tat[10],wt[10],ct[10];
    printf("enter the number of processes");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        id[i]=1;
        printf("enter the arrival time and bus time for the process %d  :\n",i);
        scanf("%d%d",&at[i],&bt[i]);
    }
    for(int i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(at[j]>at[j+1]||at[j]==at[j+1]&&bt[j]>bt[j+1]){
                int temp;
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                temp=bt[j];
                bt[j]=bt[j+1];
                at[j+1]=temp;

                temp=id[j];
                id[j]=id[j+1];
                id[j+1]=temp;
            }
        }
    }
    ct[1]=at[1]+bt[1];
    for(i=2;i<=n;i++){
        if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
        }
        else{
            ct[i]=ct[i-1]+bt[i];
        }
    }

    for(i=1;i<=n;i++){
        tat[i]=wt[i]+bt[i];

    }
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i=1;i<=n;i++){
        printf("PID%d\tAT%d\tBT%d\tWT%d\tTAT%d\n",id[i],at[i],bt[i],wt[i],tat[i]);
    }
}
