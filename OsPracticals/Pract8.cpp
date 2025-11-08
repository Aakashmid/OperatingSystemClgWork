#include<iostream>
#include<vector>
using namespace std;

struct Process{
        int pid;
        int arrival_time;
        int burst_time;
        int finish_time;
        int turnaround_time;
        int waiting_time;
};

// schedule proccess
void FCFSScheduling(vector<Process> &processes){
        // sort processes by arrival time
         for (int i = 0; i < processes.size(); i++){
                for (int j = i + 1; j < processes.size(); j++){
                        if (processes[i].arrival_time > processes[j].arrival_time){
                                swap(processes[i], processes[j]);
                        }
                }
        }


        int current_time=0;
        for(int i=0;i<processes.size();i++){
                Process &p=processes[i];
                if(current_time < p.arrival_time ){
                        current_time=p.arrival_time;
                }
                p.finish_time=current_time+p.burst_time;
                current_time=p.finish_time;
                p.turnaround_time= p.finish_time-p.arrival_time;
                p.waiting_time= p.turnaround_time-p.burst_time;
        }

}


// function to display result
void printSchedulingResults(const vector<Process>& processes) {
    cout<<"FCFS scheduling result :- \n";
    cout << "PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t"
                  << p.arrival_time << "\t"
                  << p.burst_time << "\t"
                  << p.finish_time << "\t\t"
                  << p.waiting_time << "\t"
                  << p.turnaround_time << "\n";
    }

    //  Calculate average waiting and turnaround time
    double avgWait = 0, avgTurn = 0;
    for (const auto& p : processes) {
        avgWait += p.waiting_time;
        avgTurn += p.turnaround_time;
    }

    avgWait /= processes.size();
    avgTurn /= processes.size();

    std::cout << "Average Waiting Time: " << avgWait << "\n";
    std::cout << "Average Turnaround Time: " << avgTurn << "\n";
}


int main(){
        vector<Process> processes ={{1,0,18},{2,1,2},{3,2,3}};
        FCFSScheduling(processes); 
	printSchedulingResults(processes);
        return 0;
}
