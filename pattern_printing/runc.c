// fcfs.c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
} Process;

int compareArrival(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->arrival - p2->arrival;
}

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *proc = (Process *)malloc(n * sizeof(Process));
    for(i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Process P%d - Enter Arrival Time and Burst Time: ", i+1);
        scanf("%d %d", &proc[i].arrival, &proc[i].burst);
    }

    // Sort by arrival time
    qsort(proc, n, sizeof(Process), compareArrival);

    int time = 0;
    float totalWaiting = 0, totalTurnaround = 0;
    for(i = 0; i < n; i++) {
        if(time < proc[i].arrival)
            time = proc[i].arrival;
        time += proc[i].burst;
        proc[i].completion = time;
        proc[i].turnaround = proc[i].completion - proc[i].arrival;
        proc[i].waiting = proc[i].turnaround - proc[i].burst;
        totalWaiting += proc[i].waiting;
        totalTurnaround += proc[i].turnaround;
    }

    printf("\nFCFS Scheduling:\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].arrival, proc[i].burst,
               proc[i].completion, proc[i].turnaround, proc[i].waiting);
    }
    printf("Average Turnaround Time = %.2f\n", totalTurnaround/n);
    printf("Average Waiting Time = %.2f\n", totalWaiting/n);

    free(proc);
    return 0;
}
