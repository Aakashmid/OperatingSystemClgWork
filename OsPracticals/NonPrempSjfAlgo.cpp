#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int finish_time;
    int turnaround_time;
    int waiting_time;
    bool isCompleted = false;
};

// function for sort condition
bool sortByArrivalTime(Process a, Process b)
{
    if (a.arrival_time == b.arrival_time)
    {
        return a.burst_time < b.burst_time;
    }
    return a.arrival_time < b.arrival_time; // Sort by arrival time
}


// calculate and print average waiting and turnaround time
void SjfScheduling(vector<Process> &processes)
{

        sort(processes.begin(), processes.end(), sortByArrivalTime); // Sort processes  by arrival time and burst time 
        int current_time = 0;
        int completedProcesses = 0;

        while (completedProcesses < processes.size())
        {
                int index = -1; // shortest Job Index
                int minBurstTime = INT_MAX;
                for (int i = 0; i < processes.size(); i++)
                {

                        if (processes[i].arrival_time <= current_time && !processes[i].isCompleted && processes[i].burst_time < minBurstTime)
                        {
                                index = i;
                                minBurstTime = processes[i].burst_time;
                        }
                }

                if (index == -1)
                {
                        current_time++; // if no process is found, increment current time (cpu is idle)
                        continue;
                }
                else
                {
                        Process &p = processes[index];
                        p.finish_time = current_time + p.burst_time;
                        current_time = p.finish_time;
                        p.turnaround_time = p.finish_time - p.arrival_time;
                        p.isCompleted = true;
                        p.waiting_time = p.turnaround_time - p.burst_time;
                        completedProcesses++;
                }
        }
}


// Function to display the scheduling results
void printSchedulingResults(const vector<Process>& processes) {
    cout << "Non Preemptive SJF scheduling result :-\n\n";
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



int main()
{


    vector<Process> processes = {{1, 2, 4}, {2, 5, 3}, {3, 0, 2}, {4, 5, 1}, {5, 2, 3}}; // id , arrival time, burst time

    SjfScheduling(processes);

    printSchedulingResults(processes);

    return 0;
}
