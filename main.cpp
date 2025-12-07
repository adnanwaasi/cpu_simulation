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
   // add priority to the header
    cout << "processes "<< endl;
    cout << "PID\tAT\tBT\tPRI\tCT\tTAT\tWT\n";
    double sum_tat=0.0 , sum_wt=0.0 ;

    for(auto &p:procs){
        cout<< p.pid << "\t" << p.arrival_time << "\t"<<p.burst_orig <<  "\t" << p.priority << "\t" << p.completion << "\t"<< p.turnaround_time << "\t"<< p.waiting_time << "\n";
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
    cout << "waiting time " << endl;

    for(auto &pr : gantt ){
        cout << " P" << pr.first << " =" << pr.second<<endl ;
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
   sort(procs.begin(), procs.end(), [] ( const Process &a , const Process &b) {
        if (a.arrival_time==b.arrival_time){
            return a.pid < b.pid ;
        } 
        return a.arrival_time < b.arrival_time ;
    
        });

        int time = 0;
        vector<pair<int,int>> timeline ;
        for(auto &p:procs){
            if(time<p.arrival_time) time=p.arrival_time;
            timeline.push_back({p.pid,time});
            time += p.burst_time ; 
            p.completion=time ;
            p.turnaround_time = p.completion - p.arrival_time;
            p.waiting_time = p.turnaround_time - p.burst_time ;
   } 
    print_result(procs, timeline);

}


// just two more scheduling algorithms to go preemptive SJF and priority scheduling

void preemptive_priority(vector<Process> &procs){
    int n = procs.size();
    cout << "Simulating Preemptive Priority Scheduling Algorithm\n";
    // through goes the code using heaps 
    int time =0 , completed =0 ;
    vector<pair<int,int>> gantt ;

    int last_pid = -1 ;

    priority_queue< tuple<int,int,int> , 
    vector<tuple<int,int,int>> ,
     greater<>> 
        pq ; // min-heap based on priority

    while(completed < n ){
        for(int i=0;i<n;i++){
            if(!procs[i].finished && procs[i].arrival_time ==time )
                pq.push({procs[i].priority ,procs[i].pid,i }); 
            
            }
        if(pq.empty()){
            time++;
            continue ; 
            } 
        auto [pri,pid,idx]=pq.top();
        pq.pop();

        if(last_pid != pid){
            gantt.push_back({pid,time});
            last_pid=procs[idx].pid ;

        }
        procs[idx].burst_time--;
        time++;

        if (procs[idx].burst_time>0){
            pq.push({procs[idx].priority, procs[idx].pid, idx});
        } else {
            procs[idx].completion = time ;
            procs[idx].turnaround_time= time - procs[idx].arrival_time;
            procs[idx].waiting_time = procs[idx].turnaround_time - procs[idx].burst_orig;
            procs[idx].finished = true ;
            completed++;
        }
        }
    print_result(procs, gantt);     
    }


// okay one last scheduling algorithm to go preemptive SJF

void preemptive_SJF(vector<Process> &procs){
    cout << "Simulating Preemptive SJF Scheduling Algorithm\n";
    // through goes the code using heaps 
    int n = procs.size();
    int time =0 , completed =0 ;
    vector<pair<int,int>> gantt;
    int last_pid = -1 ;

    priority_queue< tuple<int,int,int> , 
    vector<tuple<int,int,int>> , 
     greater<>> 
        pq ; // min-heap based on burst time
    while(completed < n ){
        for(int i=0;i<n;i++){
            if(!procs[i].finished && procs[i].arrival_time ==time )
                pq.push({procs[i].burst_time ,procs[i].pid,i });
        }
    
    if (pq.empty()){
        time++;
        continue ; 
    } 
    auto [bt,pid,idx]=pq.top();
    pq.pop();
    if(last_pid != pid){
        gantt.push_back({pid,time});
        last_pid=procs[idx].pid ;

    }
    procs[idx].burst_time--;
    time++; 
    if (procs[idx].burst_time>0){
        pq.push({procs[idx].burst_time, procs[idx].pid, idx});
    } else {
        procs[idx].completion = time ;
        procs[idx].turnaround_time= time - procs[idx].arrival_time;
        procs[idx].waiting_time = procs[idx].turnaround_time - procs[idx].burst_orig;
        procs[idx].finished = true ;
        completed++;
    }
    }
    print_result(procs, gantt);
}
    
int main(){
    /*
        Let's create some processes to simulate the scheduling algorithm 
    */
    vector<Process> processes = {
        {1,0,5,5,2},
        {2,1,3,3,1},
        {3,2,8,8,4},
        {4,3,6,6,3}
    };
        preemptive_SJF(processes);

    return 0;
}                          