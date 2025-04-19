#include <iostream>
#include <vector>
#include <iomanip>  // used for setw() function
using namespace std;

// Structure to represent a process
struct Process
{
    int id;              // Process ID
    int arrival_time;    // Arrival time
    int burst_time;      // Burst time
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time;    // Waiting time
};


// Function to calculate completion, turnaround and waiting times
void calculateTimes(vector<Process> &processes)
{
    int current_time = 0;

    // Sort processes by arrival time
    for (int i = 0; i < processes.size(); i++)
    {
        for (int j = i + 1; j < processes.size(); j++)
        {
            if (processes[i].arrival_time > processes[j].arrival_time)
            {
                swap(processes[i], processes[j]);
            }
        }
    }


    for (auto &process : processes)
    {
        // If current time is less than arrival time, CPU will be idle
        if (current_time < process.arrival_time)
        {
            current_time = process.arrival_time;
        }


        process.completion_time = current_time + process.burst_time;

        // Calculate turnaround time (completion time - arrival time)
        process.turnaround_time = process.completion_time - process.arrival_time;

        // Calculate waiting time (turnaround time - burst time)
        process.waiting_time = process.turnaround_time - process.burst_time;

        // Update current time
        current_time = process.completion_time;
    }
}

// Function to display the processes after  schedule and average  turnaround and waiting times
void displaySchedule(const vector<Process> &processes)
{
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;

    cout << "\nProcess Schedule:" << endl;
    cout << setw(5) << "PID"
         << setw(10) << "Arrival"
         << setw(10) << "Burst"
         << setw(15) << "Completion"
         << setw(15) << "Turnaround"
         << setw(10) << "Waiting" << endl;
    cout << string(65, '-') << endl;

    for (const auto &process : processes)
    {
        cout << setw(5) << process.id
             << setw(10) << process.arrival_time
             << setw(10) << process.burst_time
             << setw(15) << process.completion_time
             << setw(15) << process.turnaround_time
             << setw(10) << process.waiting_time << endl;

        avg_turnaround_time += process.turnaround_time;
        avg_waiting_time += process.waiting_time;
    }

    avg_turnaround_time /= processes.size();
    avg_waiting_time /= processes.size();

    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2)
         << avg_turnaround_time << endl;
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
}

int main()
{
    vector<Process> processes = {
        {1, 0, 18, 0, 0, 0}, // Process 1: arrival time = 0, burst time = 18
        {2, 1, 2, 0, 0, 0}, // Process 2: arrival time = 1, burst time = 2
        {3, 2, 3, 0, 0, 0}, // Process 3: arrival time = 2, burst time = 3
    };

    calculateTimes(processes);
    displaySchedule(processes);

    return 0;
}
