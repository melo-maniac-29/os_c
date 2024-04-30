The provided C code implements the Shortest Job First (SJF) scheduling algorithm with non-preemptive scheduling for processes with priorities. Here's a detailed explanation:

1. Header Inclusion:

<stdio.h>: Provides standard input/output functions (e.g., printf, scanf).
2. Function Declarations:

void swap(int *a, int *b): This function swaps the values of two integer variables pointed to by a and b. It's used for sorting processes based on priority.
3. Main Function:

int main(): This is the program's entry point.
4. Variable Declarations:

bt[10]: Array to store burst times of processes (up to 10).
p[10]: Array to store process IDs (0 to 9).
x: Integer variable used for calculating completion times.
ta: Variable intended for total turnaround time (not used in this implementation).
wt[10]: Array to store waiting times of processes.
n: Integer variable to store the total number of processes entered by the user.
ct[10]: Array to store completion times of processes.
i, j: Loop counters.
pr[10]: Array to store priorities of processes (higher value indicates higher priority).
tat: Variable to store total turnaround time (used for calculating average).
twt: Variable to store total waiting time (used for calculating average).
5. User Input:

Prompts the user to enter the total number of processes (n).
Reads the number of processes using scanf.
6. Input Burst Time and Priority:

Uses a loop (for(i =0;i<n;i++)) to iterate through processes.
Prompts the user to enter the burst time and priority for each process P[i].
Reads burst time and priority using scanf and stores them in bt[i] and pr[i], respectively.
Assigns the process ID i to the p[i] array (for tracking process order later).
7. Sorting by Priority (Non-Preemptive):

Uses nested loops (for(i = 0;i<n;i++) { for(j=i+1;j<n; j++){ ... } }) to sort processes based on priority in descending order (higher priority first).
The swap function is used to exchange burst times, priorities, and process IDs within the loops (swap(&pr[i],&pr[j]), etc.) if the current process (i) has a lower priority than the next process (j).
This ensures higher priority processes are processed first, even if they have longer burst times compared to lower priority processes.
8. Calculating Completion Times:

x = bt[0]: Initializes x with the burst time of the first process (highest priority).
Uses a loop (for(i = 0;i<n;i++)) to calculate completion times for all processes.
ct[i] = x: Sets the completion time of process i to the current value of x.
x = x + bt[i+1]: Increments x by the burst time of the next process, effectively calculating the completion time based on the previous process's completion and the current process's burst time.
9. Calculating Waiting Times:

Uses a loop (for(i = 0;i<n;i++)) to calculate waiting times for all processes.
wt[i] = ct[i] - bt[i]: Calculates the waiting time for process i by subtracting its burst time from its completion time. This represents the time the process spent waiting before execution.
10. Output:

Prints a table header with process ID, burst time, priority, completion time, turnaround time (calculated as completion time), and waiting time.
Uses a loop (for(int i = 0;i<n;i++)) to print details for each process in a formatted table.
11. Calculating Average Waiting Time and Turnaround Time:

for(i = 0;i<n;i++){ twt=twt+wt[i]; }: Calculates the total waiting time (twt) by summing up the waiting times of all processes.
for(int i = 0;i<n;i++){ tat=tat+ct[i]; }: Calculates