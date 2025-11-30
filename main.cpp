#include <bits/stdc++.h>

using namespace std;

struct Process {
    int pid ;
    int arrival_time ;
    int burst_time ;
    int burst_orig;
    int priority;
    int completion=0;
    int waiting_time=0;
    int turnaround_time=0;
    bool finished =false ; 
};

void print_result( const vector<Process> &procs , const vector<pair<int,int>> gantt ){
    /*
        what does this function do?
        This function prints the results of the scheduling simulation.

        procs : Data structure containing all processes 
        gantt : Gantt chart representation of process execution 

        let this re-awaken your memory on Gantt charts:
        | P1 | P2 | P3 |
        0    3    7    10

        now let's write this code 
    */
    cout << "processes "<< endl;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    double sum_tat=0.0 , sum_wt=0.0 ;
    

}