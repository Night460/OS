#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst;
};

void fcfs(struct Process processes[], int num_processes) {
    int completion_time[num_processes];
    int current_time = 0;

    for (int i = 0; i < num_processes; i++) {
        current_time = (current_time > processes[i].arrival) ? current_time : processes[i].arrival;
        current_time += processes[i].burst;
        completion_time[processes[i].id - 1] = current_time;
        printf("Process %d: Completion Time = %d\n", processes[i].id, current_time);
    }
}

int main() {
    struct Process processes[] = {
        {1, 0, 5},
        {2, 1, 3},
        {3, 2, 8}
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    printf("Non-Preemptive (FCFS) Scheduling:\n");
    fcfs(processes, num_processes);

    return 0;
}

