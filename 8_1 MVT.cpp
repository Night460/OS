#include <stdio.h>

int main() {
    int m, p, i, count = 0; 

    printf("Enter memory capacity: ");
    scanf("%d", &m); 

    printf("Enter number of processes: ");
    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        int m1;
        printf("\nEnter memory required for process %d: ", i + 1);
        scanf("%d", &m1);
        count += m1; 

        if (count > m) {
            printf("\nNo further memory remaining.\n");
            break;
        } 

        printf("Memory allocated for process %d: %d, Remaining memory: %d\n", i + 1, m1, m - count);
    } 

    return 0;
}

