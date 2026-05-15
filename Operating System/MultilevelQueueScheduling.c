
/*
* Queue 1 → Time Quantum = 4
* Queue 2 → Time Quantum = 5
* Queue 3 → FCFS
* New processes always enter Queue 1
* Higher-priority queues preempt lower-priority queues
*/
#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst;
    int remaining;
    int completion;
};

int main() {
    struct Process p[6] = {
        {1,0,10,10,0},
        {2,1,5,5,0},
        {3,6,4,4,0},
        {4,7,9,9,0},
        {5,17,2,2,0},
        {6,19,5,5,0}
    };

    int time = 0;
    int completed = 0;

    printf("MLFQ Scheduling Execution:\n\n");

    while(completed < 6) {

        int executed = 0;

        // Queue 1 
        for(int i=0;i<6;i++) {
            if(p[i].arrival <= time && p[i].remaining > 0) {

                // process still in Queue 1 if remaining == burst
                if(p[i].remaining == p[i].burst) {

                    int run = (p[i].remaining > 4) ? 4 : p[i].remaining;

                    printf("Time %d -> %d : P%d (Q1)\n",
                           time, time+run, p[i].id);

                    time += run;
                    p[i].remaining -= run;
                    executed = 1;

                    if(p[i].remaining == 0) {
                        p[i].completion = time;
                        completed++;
                    }
                }
            }
        }

        //  Queue 2 
        for(int i=0;i<6;i++) {
            if(p[i].arrival <= time && p[i].remaining > 0) {

                // Queue 2 condition
                if(p[i].remaining < p[i].burst && p[i].remaining > 5) {

                    int run = 5;

                    printf("Time %d -> %d : P%d (Q2)\n",
                           time, time+run, p[i].id);

                    time += run;
                    p[i].remaining -= run;
                    executed = 1;
                }
                else if(p[i].remaining > 0 && p[i].remaining <= 5) {

                    printf("Time %d -> %d : P%d (Q2 Finish)\n",
                           time, time+p[i].remaining, p[i].id);

                    time += p[i].remaining;
                    p[i].remaining = 0;
                    p[i].completion = time;
                    completed++;
                    executed = 1;
                }
            }
        }

        // if no process executed
        if(!executed)
            time++;
    }

    printf("\nFinal Results:\n");

    float avgWT = 0, avgTAT = 0;

    for(int i=0;i<6;i++) {
        int tat = p[i].completion - p[i].arrival;
        int wt = tat - p[i].burst;

        avgWT += wt;
        avgTAT += tat;

        printf("P%d -> CT=%d TAT=%d WT=%d\n",
               p[i].id,
               p[i].completion,
               tat,
               wt);
    }

    avgWT /= 6;
    avgTAT /= 6;

    printf("\nAverage Waiting Time = %.2f\n", avgWT);
    printf("Average Turnaround Time = %.2f\n", avgTAT);

    return 0;
}
