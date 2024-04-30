The provided C code demonstrates process creation using the fork system call and includes error handling and process information retrieval:

Explanation:

Header Inclusions:

<stdio.h>: Provides standard input/output functions like printf.
<unistd.h>: Contains POSIX operating system functions, including fork.
<stdlib.h>: Often included with unistd.h, but not directly used here (may contain general utility functions).
<sys/types.h>: Includes system data types like pid_t (used for process IDs).
<sys/wait.h>: Provides functions for waiting for child processes, including wait. (Newly added in this version)
Variable Declaration:

int pid: An integer variable to store the return value of fork.
Process Creation with fork:

pid = fork(): This line attempts to create a new process using fork.
The return value of fork is stored in the pid variable.
Error Handling:

if (pid < 0) { ... }: This conditional block checks if fork failed.
If pid is less than 0, fork failed. The code prints an error message and exits with a non-zero status code (1) to indicate an error.
Child Process Execution:

else if (pid == 0) { ... }: This block executes in the child process because fork returns 0 in the child process.
The child process prints a message indicating successful creation.
It then uses getpid() to get its own process ID (PID) and getppid() to get the parent process ID (PPID) and prints them.
Parent Process Execution:

else { ... }: This block executes in the parent process because fork returns the child's PID in the parent process.
The parent process prints a message indicating successful creation.
The wait(NULL) statement (newly added) causes the parent process to wait for any child process to finish execution before continuing. Without wait, the parent might exit before the child finishes, leading to unexpected behavior.
Similar to the child process, the parent retrieves and prints its own PID and PPID using getpid() and getppid().
Process Termination:

return 0;: Both parent and child processes (after waiting in the parent) return 0 to indicate successful execution.
Key Points:

This code incorporates error handling to check for fork failures.
It retrieves and prints the process IDs (PID and PPID) of both parent and child processes, allowing you to verify the process hierarchy.
The wait(NULL) statement in the parent process ensures that the parent waits for the child to finish before exiting.
Execution Flow:

The program starts in the parent process.
fork creates a child process.
The code diverges based on the return value of fork:
Parent Process:
Checks for errors from fork.
If no error, prints a message and waits for the child process.
Retrieves and prints its own PID and PPID.
Child Process:
Checks for errors from fork.
If no error, prints a message.
Retrieves and prints its own PID and PPID.
Both parent and child processes terminate.
Example Output:

Child process successfully created
Child_pid = 1234 ,Parent_pid = 4321  // (Example PIDs)
Parent process successfully created
Child_pid = 1234 ,Parent_pid = 4321  // (Example PIDs)
Additional Notes:

The actual PIDs will be different in each run.
This code provides a more robust and informative implementation of process creation with fork.