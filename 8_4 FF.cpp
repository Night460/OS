#include <stdio.h>
#include <stdlib.h>

int* first_fit(int* blocks, int* processes, int nb, int np) {
    int* allocation = (int*)malloc(np * sizeof(int));

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }
    return allocation;
}

int main() {
    int nb, np;
    printf("Enter number of blocks and processes: ");
    scanf("%d %d", &nb, &np);

    int* blocks = (int*)malloc(nb * sizeof(int));
    int* processes = (int*)malloc(np * sizeof(int));

    printf("Enter block sizes (separated by space): ");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blocks[i]);
    }

    printf("Enter process sizes (separated by space): ");
    for (int i = 0; i < np; i++) {
        scanf("%d", &processes[i]);
    }

    int* allocation = first_fit(blocks, processes, nb, np);

    printf("\nBlock_No.\tProcess_No.\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t\t%s\n", allocation[i] + 1, (allocation[i] != -1) ? "Not allocated" : "Not allocated");
    }

    free(blocks);
    free(processes);
    free(allocation);

    return 0;
}

