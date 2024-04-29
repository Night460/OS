#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
};

void round_robin(struct Process processes[], int num_processes, int quantum) {
    int total_time = 0, completed = 0;

    printf("Gantt Chart:\n");
    while (completed < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].rt > 0 && processes[i].at <= total_time) {
                if (processes[i].rt > quantum) {
                    printf("%d ", processes[i].pid);
                    total_time += quantum;
                    processes[i].rt -= quantum;
                } else {
                    printf("%d ", processes[i].pid);
                    total_time += processes[i].rt;
                    processes[i].rt = 0;
                    processes[i].ct = total_time;
                    completed++;
                    printf("| ");
                }
            }
        }
        total_time++;
    }
    printf("\n\nProcess\t AT\t BT\t CT\t TAT\t WT\n");
    float total_tat = 0, total_wt = 0;
    for (int i = 0; i < num_processes; i++) {
        int tat = processes[i].ct - processes[i].at;
        int wt = tat - processes[i].bt;
        total_tat += tat;
        total_wt += wt;
        printf("%d\t %d\t %d\t %d\t %d\t %d\n", processes[i].pid, processes[i].at, processes[i].bt, processes[i].ct, tat, wt);
    }

    float avg_tat = total_tat / num_processes;
    float avg_wt = total_wt / num_processes;
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter AT and BT for process %d: ", i + 1);
        scanf("%d %d", &processes[i].at, &processes[i].bt);
        processes[i].pid = i + 1;
        processes[i].rt = processes[i].bt;
    }

    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    round_robin(processes, num_processes, quantum);

    return 0;
}

