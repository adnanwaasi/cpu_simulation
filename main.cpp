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
