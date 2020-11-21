//C program for FCFS with Arrival Time
#include<stdio.h>

void completion_time(int processes[],int n, int at[],int bt[],int ct[]){
    int i;
    ct[0]=bt[0];
    for(i=1;i<n;i++){
    ct[i]= bt[i]+ct[i-1];
    }
}

void turn_around_time(int processes[],int n,int at[],int ct[],int tat[]){
    //tat= ct-at
    int i;
    for(i=0;i<n;i++){
    tat[i]=ct[i]-at[i];
    }
}
 void waiting_time(int processes[],int n,int bt[],int tat[],int wt[]){
    //wt=tat-bt
    int i; 
    for(i=0;i<n;i++){
    wt[i]=tat[i]-bt[i];
    }
 }

void find_time(int processes[],int n, int at[],int bt[]){
    int ct[n],wt[n],tat[n],i=0,total_tat=0,total_wt=0;
    completion_time(processes,n,at,bt,ct);
    turn_around_time(processes,n,at,ct,tat);
    waiting_time(processes,n,bt,tat,wt);
    printf("Processes   ");
    printf("Arrival Time    ");
    printf("Burst Time  ");
    printf("Completion Time     ");
    printf("Turn around Time    ");
    printf("Waiting Time    \n");
    for(i=0;i<n;i++){
        total_tat=total_tat+tat[i];
        total_wt=total_wt+wt[i];
        printf("    %d            %d              %d                 %d                  %d                   %d\n", processes[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    float avg_tat= (float)total_tat/(float)n;
    float avg_wt= (float)total_wt/(float)n;
    printf("Average Turn Around Time=%f\n",avg_tat );
    printf("Average Waiting Time=%f\n",avg_wt );
    
}

int main(){
int processes[]={1,2,3,4};
int nop=4;
int arrival_time[]={0,3,6,8};
int burst_time[]={5,9,6,4};
find_time(processes,nop,arrival_time,burst_time);
return 0;
}
