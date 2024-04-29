#include <stdio.h>

int main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    printf("Enter total memory and block size: ");
    scanf("%d %d", &ms, &bs);
    nob = ms / bs;
    ef = ms - nob * bs;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter memory required for process %d: ", i + 1);
        scanf("%d", &mp[i]);
    }
    printf("\nNo. of Blocks available in memory: %d\n", nob);
    printf("\nPROCESS \t MEMORY REQUIRED \t ALLOCATED \t INTERNAL FRAGMENTATION\n");
    for (int i = 0, p = 0; i < n && p < nob; i++) {
        printf("%d\t\t%d", i + 1, mp[i]);
        if (mp[i] <= bs) {
            printf("\t\tYES\t\t%d\n", bs - mp[i]);
            tif += bs - mp[i];
            p++;
        } else {
            printf("\t\tNO\n");
        }
    }
    if (n > nob) {
        printf("Memory is Full, Remaining Processes cannot be accommodated\n");
    }
    printf("\nTotal Internal Fragmentation is %d\n", tif);
    printf("Total External Fragmentation is %d\n", ef);
    return 0;
}

