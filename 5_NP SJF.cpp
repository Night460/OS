#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int at;
    int bt;
};

int cmp(const void *a, const void *b) {
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    
    if (p1->at != p2->at)
        return p1->at - p2->at;
    else
        return p1->bt - p2->bt;
}

void sjf() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process *p = (struct Process *)malloc(n * sizeof(struct Process));
    
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for process %d (separated by space): ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
    }
    
    qsort(p, n, sizeof(struct Process), cmp);
    
    int ct = 0, twt = 0, ttat = 0;
    printf("\nProcess\t AT\t BT\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        ct = (ct < p[i].at) ? p[i].at : ct;
        int wt = ct - p[i].at;
        twt += wt;
        int tat = wt + p[i].bt;
        ttat += tat;
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].at, p[i].bt, wt, tat);
        ct += p[i].bt;
    }
    
    float awt = (float)twt / n;
    float atat = (float)ttat / n;
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);
    
    free(p);
}

int main() {
    sjf();
    return 0;
}

