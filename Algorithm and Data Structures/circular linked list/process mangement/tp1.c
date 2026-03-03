#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;  // Used for Round Robin
} Process;

// Function Prototypes
void fifo(Process processes[], int n);
void round_robin(Process processes[], int n, int quantum);
void sjf(Process processes[], int n);
void sort_by_arrival_time(Process processes[], int n);
void sort_by_burst_time(Process processes[], int n);

int main() {
    int n, quantum;
    Process processes[MAX_PROCESSES];

    // Input process details
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);

    printf("\nFIFO Scheduling:\n");
    fifo(processes, n);

    printf("\nRound Robin Scheduling:\n");
    round_robin(processes, n, quantum);

    printf("\nSJF Scheduling:\n");
    sjf(processes, n);

    return 0;
}

// Sort processes by arrival time for FIFO
void sort_by_arrival_time(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// FIFO Scheduling
void fifo(Process processes[], int n) {
    sort_by_arrival_time(processes, n);
    
    int time = 0, total_waiting = 0, total_turnaround = 0;
    printf("Process Execution Order: ");

    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival_time)
            time = processes[i].arrival_time;

        int waiting_time = time - processes[i].arrival_time;
        total_waiting += waiting_time;
        time += processes[i].burst_time;
        int turnaround_time = time - processes[i].arrival_time;
        total_turnaround += turnaround_time;

        printf("P%d ", processes[i].id);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

// Round Robin Scheduling
void round_robin(Process processes[], int n, int quantum) {
    int time = 0, completed = 0;
    int total_waiting = 0, total_turnaround = 0;
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                printf("P%d ", processes[i].id);
                
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time;
                    int turnaround_time = time - processes[i].arrival_time;
                    int waiting_time = turnaround_time - processes[i].burst_time;
                    total_waiting += waiting_time;
                    total_turnaround += turnaround_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

// Sort processes by burst time for SJF
void sort_by_burst_time(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// SJF Scheduling
void sjf(Process processes[], int n) {
    sort_by_burst_time(processes, n);

    int time = 0, total_waiting = 0, total_turnaround = 0;
    printf("Process Execution Order: ");

    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival_time)
            time = processes[i].arrival_time;

        int waiting_time = time - processes[i].arrival_time;
        total_waiting += waiting_time;
        time += processes[i].burst_time;
        int turnaround_time = time - processes[i].arrival_time;
        total_turnaround += turnaround_time;

        printf("P%d ", processes[i].id);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}
