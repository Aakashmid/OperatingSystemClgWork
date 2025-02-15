#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<iomanip>
using namespace std;

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int finish_time;
    int turnaround_time;
    int waiting_time;
    bool isCompleted = false;
};

bool sortByArrivalTime(Process a, Process b)
{
    if (a.arrival_time == b.arrival_time)
    {
        return a.burst_time < b.burst_time;
    }
    return a.arrival_time < b.arrival_time; // Sort by arrival time
}


// calculate and print average waiting and turnaround time
void CalculateTimings(vector<Process> &processes)
{

        sort(processes.begin(), processes.end(), sortByArrivalTime); // Sort by arrival time
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




void DisplaySchedule(const vector<Process> &processes)
{
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;

    cout << "\nProcess Schedule:" << endl;
    cout << setw(5) << "PID"
         << setw(10) << "Arrival"
         << setw(10) << "Burst"
         << setw(15) << "Finish"
         << setw(15) << "Turnaround"
         << setw(10) << "Waiting" << endl;
    cout << string(65, '-') << endl;

    for (const auto &process : processes)
    {
        cout << setw(5) << process.id
             << setw(10) << process.arrival_time
             << setw(10) << process.burst_time
             << setw(15) << process.finish_time
             << setw(15) << process.turnaround_time
             << setw(10) << process.waiting_time << endl;

        avg_turnaround_time += process.turnaround_time;
        avg_waiting_time += process.waiting_time;
    }

    avg_turnaround_time /= processes.size();
    avg_waiting_time /= processes.size();

    cout << "\nAverage Turnaround Time: " <<avg_turnaround_time << endl;
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
}


int main()
{
    // vector<Process> processes = {{1, 2, 4}, {2, 5, 3}, {3, 0, 2}, {4, 5, 1}, {5, 2, 3}}; // id , arrival time, burst time
    cout << "### Non-preemptive SJF Algorithm ### \n \n";
    int n;
    cout << "Enter total processes number : ";
    cin >> n;
    vector<Process> processes;

    // taking processes input
    for (int i = 0; i < n; i++)
    {
        int id, arrival_time, burst_time;
        cout << "Enter process " << i + 1 << " arrival time : ";
        cin >> arrival_time;
        cout << "Enter process " << i + 1 << " burst time : ";
        cin >> burst_time;
        processes.push_back({i + 1, arrival_time, burst_time});
    }
    CalculateTimings(processes);

    // display updated processes data
    DisplaySchedule(processes);
    return 0;
}