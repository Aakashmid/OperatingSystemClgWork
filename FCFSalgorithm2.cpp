#include<iostream>
#include<vector>
using namespace std;

struct Process{
        int id;
        int arrival_time;
        int burst_time;
        int finish_time;
        int turnaround_time;
        int waiting_time;
};

// calculate and print average waiting and turnaround time
void CalculateAvgWT_TA(vector<Process> &processes){
        // sort processes by arrival time
         for (int i = 0; i < processes.size(); i++){
                for (int j = i + 1; j < processes.size(); j++){
                        if (processes[i].arrival_time > processes[j].arrival_time){
                                swap(processes[i], processes[j]);
                        }
                }
        }


        float avg_turnArT=0;  // average turnaround time
        float avg_waitingT=0; // average waiting time
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
                avg_waitingT+=p.waiting_time;
                avg_turnArT+=p.turnaround_time;
        }

        cout<<"Average Turnaround Time is : "<< avg_turnArT/processes.size()<<endl;
        cout<<"Average Waiting Time si : "<<avg_waitingT/processes.size()<<endl;
}



int main(){
        vector<Process> processes ={{1,0,18},{2,1,2},{3,2,3}};
        CalculateAvgWT_TA(processes); 
        return 0;
}