//Shortest Jop First preemptive implementation without Arrival time
// considering arrival time of all the processes as zero
#include<stdio.h>

// Sorting the processes according burst time
void sorting(int processes[],int n,int bt[]){
    int i,temp=0;
    for(i=0;i<n-1;i++){
    if(bt[i]>bt[i+1]){
        temp=bt[i];
        bt[i]=bt[i+1];
        bt[i+1]=temp;
        
        temp=processes[i];
        processes[i]=processes[i+1];
        processes[i+1]=temp;
    }
    }
}

void waiting_time(int processes[], int n, int bt[],int wt[] ){
    wt[0]=0;
    int i;
    for(i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
}

void turn_around_time(int processes[], int n, int bt[],int wt[],int tat[]){
    int i;
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
}

void find_time(int processes[], int n, int bt[]){
    int wt[n],tat[n],total_tat=0,total_wt=0,i=0;
    sorting(processes,n,bt);
    waiting_time(processes,n,bt,wt);
    turn_around_time(processes,n,bt,wt,tat);
    printf("Processes \t Burst Time \t Waiting Time \t Turn Around Time\n");
    for(i=0;i<n;i++){
    total_tat=total_tat+tat[i];
    total_wt=total_wt+wt[i];
    printf(" %d             \t %d           \t %d           \t %d \t\n",processes[i],bt[i],wt[i],tat[i]);
    }
    float avgtat=(float)total_tat/(float)n;
    float avgwt=(float)total_wt/(float)n;
    printf("Average Turn Around Time =%f\n", avgtat);
    printf("Average Waiting Time =%f\n", avgwt);
}

int main(){
int processes[]={1,2,3,4};
int nop=4;
int burst_time[]={1,4,5,4};
find_time(processes,nop,burst_time);
return 0;
}
//OUTPUT---
/*
Processes 	 Burst Time 	 Waiting Time 	 Turn Around Time
 1             	 1           	 0           	 1 	
 2             	 4           	 1           	 5 	
 4             	 4           	 5           	 9 	
 3             	 5           	 9           	 14 	
Average Turn Around Time =7.250000
Average Waiting Time =3.750000
*/
