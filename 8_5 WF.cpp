#include <stdio.h>
#include <stdlib.h>

int* worst_fit(int* blocks, int* processes, int nb, int np) {
    int* allocation = (int*)malloc(np * sizeof(int));
    for (int i = 0; i < np; i++) {
        int highest = -1;
        for (int j = 0; j < nb; j++) {
            if (blocks[j] >= processes[i] && blocks[j] > highest)
                allocation[i] = j, highest = blocks[j];
        }
        if (allocation[i] != -1)
            blocks[allocation[i]] -= processes[i];
    }
    return allocation;
}

int main() {
    int nb, np;
    printf("Enter number of blocks and processes: ");
    scanf("%d %d", &nb, &np);

    int* blocks = (int*)malloc(nb * sizeof(int));
    int* processes = (int*)malloc(np * sizeof(int));

    printf("Enter block sizes: ");
    for (int i = 0; i < nb; i++)
        scanf("%d", &blocks[i]);

    printf("Enter process sizes: ");
    for (int i = 0; i < np; i++)
        scanf("%d", &processes[i]);

    int* allocation = worst_fit(blocks, processes, nb, np);

    printf("\nProcess_No.\tBlock_No.\n");
    for (int i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\n", i + 1, allocation[i] + 1);
        else
            printf("%d\t\tNot allocated\n", i + 1);
    }

    free(blocks);
    free(processes);
    free(allocation);

    return 0;
}


