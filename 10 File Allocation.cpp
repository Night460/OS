#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

struct File {
    char name[20];
    int startBlock;
    int length;
};

int main() {
    struct File files[MAX_FILES];
    int n, i, j, blocks[100] = {0};

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter file %d name: ", i + 1);
        scanf("%s", files[i].name);

        printf("Enter the starting block of file %s: ", files[i].name);
        scanf("%d", &files[i].startBlock);

        printf("Enter the length of file %s: ", files[i].name);
        scanf("%d", &files[i].length);

        for (j = files[i].startBlock; j < files[i].startBlock + files[i].length; j++) {
            if (blocks[j] == 1) {
                printf("Block already in use. Please enter a different block.\n");
                return 1; // Exit with error code if block is already in use
            }
            blocks[j] = 1;
        }
    }

    printf("\nFilename\tStart block\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\n", files[i].name, files[i].startBlock, files[i].length);
    }

    return 0;
}

