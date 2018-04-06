#include<stdio.h> 
#include<conio.h>

int main() 
{ 

  int add_up,j,n,time,left,flag=0,TQ; 
  int WaitingTime=0,TAT=0,Arrival_time[10],Burst_time[10],rt[10]; 
  printf("                                **********ROUND ROBIN ALGORITHM**************    \n");
  printf("                                          ---------------------                   \n");
  printf("Enter Total number of Processes:\t"); 
  scanf("%d",&n); 
  left=n; 
  for(add_up=0;add_up<n;add_up++) 
  { 
    printf("\nKindly enter Arrival Time & Burst time :",add_up+1);  
    scanf("%d",&Arrival_time[add_up]); 
    scanf("%d",&Burst_time[add_up]); 
    rt[add_up]=Burst_time[add_up]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&TQ); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,add_up=0;left!=0;) 
  { 
    if(rt[add_up]<=TQ && rt[add_up]>0) 
    { 
      time+=rt[add_up]; 
      rt[add_up]=0; 
      flag=1; 
    } 
    else if(rt[add_up]>0) 
    { 
      rt[add_up]-=TQ; 
      time+=TQ; 
    } 
    if(rt[add_up]==0 && flag==1) 
    { 
      left--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",add_up+1,time-Arrival_time[add_up],time-Arrival_time[add_up]-Burst_time[add_up]); 
      WaitingTime+=time-Arrival_time[add_up]-Burst_time[add_up]; 
      TAT+=time-Arrival_time[add_up]; 
      flag=0; 
    } 
    if(add_up==n-1) 
      add_up=0; 
    else if(Arrival_time[add_up+1]<=time) 
      add_up++; 
    else 
      add_up=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",WaitingTime*1.0/n); 
  printf("Avg Turnaround Time = %f",TAT*1.0/n); 
  
  return 0; 
}
