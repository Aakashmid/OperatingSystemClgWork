#include<iostream>
#include<vector>
#include<algorithm>  // for sort method
using namespace std;

// Non-preemptive priority based algorithm implementation

struct Process {
	int pid;
	int arrival_time;
	int burst_time;
	int priority;  // greater value of priority mean highest priority 
	int finish_time;
	int turnaround_time;
	int waiting_time;
	bool isCompleted=false;
};


bool sortByPriority(Process a, Process b){
	if(a.arrival_time == b.arrival_time){
		return a.priority < b.priority ;
	}
	return a.arrival_time < b.arrival_time;
}

void calculateTAT_WT(vector<Process> &processes) // calculate turnaround and and waiting time 
{	
	int current_time= 0;
	int completed_processes=0;
	float total_waiting_time=0;
	float total_turnaround_time=0;


	while(completed_processes<processes.size()){
		int index=-1; // to store index of highest priority process arrived ;
			
		int max_priority = 0;
		for(int i=0;i<processes.size();i++){
			if(processes[i].arrival_time<= current_time && !processes[i].isCompleted && processes[i].priority > max_priority){
				index++;  // selected current process 
			  	max_priority=processes[i].priority;
			}
		}	


		if(index==-1){
			current_time++;
		}
		else{
			Process &p = processes[index];
			p.finish_time = current_time + p.burst_time;
                        current_time = p.finish_time;
                        p.turnaround_time = p.finish_time - p.arrival_time;
                        p.isCompleted = true;
                        p.waiting_time = p.turnaround_time - p.burst_time;
			total_waiting_time+=p.waiting_time;
			total_turnaround_time=p.turnaround_time;
                        completed_processes++;
		}
	}
	cout<<"Average waiting time is : "<<total_waiting_time/processes.size()<<endl;;
	cout<<"Average turnaround time is : "<< total_turnaround_time/processes.size()<<endl;
}




int main(){
	vector<Process> processes = {{1, 2, 4,3}, {2, 5, 3,1}, {3, 0, 2,4}, {4, 5, 1}, {5, 2, 3,2}}; // id , arrival time, burst time
	calculateTAT_WT(processes);
	return 0;
}

