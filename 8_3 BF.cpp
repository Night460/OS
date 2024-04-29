#include <stdio.h>

int main() {
    int fragment[20] = {0}, b[20] = {0}, p[20] = {0}, barray[20] = {0}, parray[20] = {0};
    int nb, np;

    printf("Enter number of blocks and processes: ");
    scanf("%d %d", &nb, &np);

    printf("Enter sizes of blocks:\n");
    for (int i = 1; i <= nb; i++) {
        printf("Block No. %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter sizes of processes:\n");
    for (int i = 1; i <= np; i++) {
        printf("Process No. %d: ", i);
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= np; i++) {
        int lowest = 9999;
        for (int j = 1; j <= nb; j++) {
            if (!barray[j] && b[j] >= p[i] && b[j] - p[i] < lowest) {
                parray[i] = j;
                lowest = b[j] - p[i];
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
    }

    printf("\nProcess_No.\tProcess_size\tBlock_No.\tBlock_size\tFragment\n");
    for (int i = 1; i <= np; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], parray[i], b[parray[i]], fragment[i]);
    }

    return 0;
}

