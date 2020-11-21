// C program for FCFS scheduling without arrival time
#include<stdio.h>

void waiting_time(int processses[],int n, int bt[],int wt[]){
    wt[0]=0;
    int i;
    for(i=1;i<n;i++){
    wt[i]=bt[i-1]+wt[i-1];
    }
}

void turn_around_time(int processses[],int n, int bt[],int wt[],int tat[]){
    int i;
    for(i=0;i<n;i++){
    tat[i]=bt[i]+wt[i];
    }
}

void avg_times(int processes[], int n, int bt[] ){
    int wt[n],tat[n], total_tat=0, total_wt=0 , i;
    waiting_time(processes,  n, bt, wt);
    turn_around_time(processes, n, bt,wt,tat);
    printf(" Process | Burst Time | Waiting Time | Turn Around Time\n");
    for(i=0;i<n;i++){
    total_wt=total_wt+wt[i];
    total_tat=total_tat+tat[i];
    printf("      %d        %d          %d             %d    \n", processes[i],bt[i],wt[i],tat[i]);
    }
    float avg_wt=(float)total_wt/(float)n;
    float avg_tat=(float)total_tat/(float)n;
    printf("Average Waiting Time = %f\n",avg_wt);
    printf("Average Turn Around Time = %f",avg_tat);
    printf("\n");
}

int main(){
// Process ID's
int processes[]={1,2,3,4};\
int nop= sizeof(processes)/sizeof(processes[1]);
//Burst Time of the processes
int burst_time[]={10,5,8,4};

avg_times(processes,nop,burst_time);
return 0;
}
