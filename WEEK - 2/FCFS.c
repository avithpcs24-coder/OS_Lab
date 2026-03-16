#include<stdio.h>
int main(){
int n,at[20],bt[20],wt[20],ct[20],tat[20];
int i;
float twt=0.0,ttat=0.0,awt,att;
printf("Enter the number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("Enter the Arrival time for Process %d:",i+1);
    scanf("%d",&at[i]);
    printf("Enter the Burst time for Process %d:",i+1);
    scanf("%d",&bt[i]);

}
for(i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(at[j]>at[j+1]){
            int temp=at[j];
            at[j]=at[j+1];
            at[j+1]=temp;

            int temp1=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=temp1;
        }
    }
}
ct[0]=at[0]+bt[0];
wt[0]=0;
tat[0]=bt[0];
for(i=1;i<n;i++){
    if(ct[i-1]<at[i]){
        ct[i]=at[i]+bt[i];
        wt[i]=0;
    }else{
         wt[i]=ct[i-1]-at[i];
         ct[i]=ct[i-1]+bt[i];
}
tat[i]=wt[i]+bt[i];
}
for(i=0;i<n;i++){
    twt+=wt[i];
    ttat+=tat[i];

}
awt=twt/n;
att=ttat/n;
printf("\nProcess\tAT\tBT\tCT\tWT\tTAT");
for(i=0;i<n;i++){
    printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
}
printf("\nAverage Waiting time=%.2f",awt);
printf("\nAverage Turnaround time=%.2f",att);
}
