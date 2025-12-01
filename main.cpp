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

    for(auto &p:procs){
        cout<< p.pid << "\t" << p.arrival_time << "\t"<<p.burst_orig << "\t"<< p.priority << "\t"<< p.completion << "\t"<< p.turnaround_time << "\t"<< p.waiting_time << "\n";
        sum_tat += p.turnaround_time ;
        sum_wt += p.waiting_time ;
    }

    /* 
    how to iterate over a vector of pairs
    
    well , it's similar to over a vector of any other data type 

        for(auto &pr : ganttt ){
            pr.first  --> first element of pair 
            pr.second --> second element of pair 
        }
    */

    for(auto &pr : gantt ){
        cout << " P" << pr.first << " |" << pr.second ;
    }

}

void simulating_FDFS(vector<Process> &procs ){

    cout << "Simulating FDFS Scheduling Algorithm\n";
    /* 
    i am copying the code tbh i am still learning about stuffs like the lambda functions and all
    []  this is called a lambda capture clause
    ()  this is the parameter list
    {}  this is the function body
    -> return type
    */
   sort(procs.begin(), procs.end(), [] ( const Process $a , const Process &b) {
        if (a.arrival_time==b.arrival_time){
            return a.pid < b.pid ;
        } 
        return a.arrival_time < b.arrival_time ;
    
        });

        int time = 0;
        vector<pair<int,int>> timeline ;
        for(auto &p:procs){
            
        }
   } 
}