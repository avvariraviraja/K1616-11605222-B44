#include<iostream>
#include<conio.h>
using namespace std;
struct processes
{
	int Arrival_time,BurstTime,p_id,WaitingTime;
	bool exe;
}p[10];
void sorted(processes *Ready_queue[10],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(Ready_queue[j]->BurstTime>Ready_queue[j+1]->BurstTime)
			{
				processes *temp=Ready_queue[j];
				Ready_queue[j]=Ready_queue[j+1];
				Ready_queue[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n,clk;
	cout<<"                   ****************Shortest Job First Scheduling Approach*******************\n";
	cout<<"                                   --------------------------------------                    \n\n";
	cout<<"Kindly Enter Number Of Processes: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Arrival time for process "<<i+1<<":\n";
		cin>>p[i].Arrival_time;
		p[i].p_id=i+1;
		p[i].BurstTime=p[i].Arrival_time*2;
		p[i].exe=false;
		p[i].WaitingTime=0;
	}
	cout<<"Processes Details are shown in Tabular form : \n\n";
	cout<<"|ID\t|Arrival Time|\t|Burst Time|\n";
	cout<<"----------------------------------\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i].p_id<<"\t"<<p[i].Arrival_time<<"\t\t"<<p[i].BurstTime;
		cout<<"\n";
		cout<<"-----------------------------------\n";
	}

	processes p1[n],*Ready_queue[n];
	int Queue_size=0;
	clk=0;
	processes *Executes = NULL;
	while(true)
	{
		bool check=true;
		for(int i=0;i<n;i++)
		{
			if(p[i].exe==false)
			{
				check=false;
				break;
			}
		}	
		if(check)
			break;
		for(int i=0;i<n;i++)
		{
			if(p[i].Arrival_time==clk && p[i].exe==false){
				Ready_queue[Queue_size]=&p[i];
				Queue_size++;
			}
		}
		if ( Executes != NULL && Executes->BurstTime + Executes->WaitingTime + Executes->Arrival_time == clk) {
			Executes = NULL;
		}
		if(Queue_size>0 && Executes == NULL)
		{
			sorted(Ready_queue,Queue_size);
			Ready_queue[Queue_size-1]->exe=true;
			Executes = Ready_queue[Queue_size-1];
			cout<<"process\t"<<Ready_queue[Queue_size-1]->p_id<<" is executed\n"<<endl;
			Queue_size--;
		}
		for(int j=0;j<Queue_size;j++)
		{
			Ready_queue[j]->WaitingTime++;
		}
		clk++;
	}
	int Totaltime=0;
	float TAT=0;
	float totalwaiting=0;
	for(int i=0;i<n;i++)
	{
		totalwaiting += p[i].WaitingTime;
		Totaltime=p[i].BurstTime+p[i].WaitingTime+p[i].Arrival_time+Totaltime;
		TAT=(p[i].BurstTime+p[i].WaitingTime)+TAT;
	}
	cout<<"\nTotal Complete Time     :\t"<<Totaltime<<endl;
	cout<<"\nTotal Turn Around Time  :\t"<<TAT<<endl;
	cout<<"\nAverage Turn Around Time:\t"<<(TAT)/n<<endl;
	cout<<"\nAverage Waiting Time    :\t"<<(totalwaiting)/n<<endl;
}
