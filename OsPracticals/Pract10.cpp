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


void NonPreempPriorityScheduling(vector<Process> &processes) // calculate turnaround and and waiting time 
{	
	int current_time= 0;
	int completed_processes=0;

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
                        completed_processes++;
		}
	}

}



// Function to display the scheduling results
void printSchedulingResults(const vector<Process>& processes) {
    cout << "Non Preemptive Priority scheduling result :-\n\n";
    cout << "PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n";

    for (const auto& p : processes) {
        cout << p.pid << "\t"
             << p.arrival_time << "\t"
             << p.burst_time << "\t"
             << p.finish_time << "\t\t"
             << p.waiting_time << "\t"
             << p.turnaround_time << "\n";
    }

    // Calculate average waiting and turnaround time
    double avg_wait = 0, avg_turn = 0;
    for (const auto& p : processes) {
        avg_wait += p.waiting_time;
        avg_turn += p.turnaround_time;
    }

    avg_wait /= processes.size();
    avg_turn /= processes.size();

    cout << "\nAverage Waiting Time: " << avg_wait << "\n";
    cout << "Average Turnaround Time: " << avg_turn << "\n";
}


int main(){
	vector<Process> processes = {{1, 0, 2,2}, {2, 1, 1,1}, {3, 2, 8,4}, {4, 3, 4,2}, {5, 4, 5,3}}; // id , arrival time, burst time
	NonPreempPriorityScheduling(processes);
	
	printSchedulingResults(processes);

	return 0;
}

