#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PS 1024
#define NP 16
#define MS 4

typedef struct {
    int valid;
    int frame;
} PTE;

PTE* init_PT() {
    PTE* PT = (PTE*)malloc(NP * sizeof(PTE));
    for (int i = 0; i < NP; i++) {
        PT[i].valid = 0;
        PT[i].frame = -1;
    }
    return PT;
}

void handle_PF(PTE* PT, int page_num) {
    printf("Page fault for page %d: Loading page %d into memory\n", page_num, page_num);
    PT[page_num].valid = 1;
    PT[page_num].frame = rand() % MS;
}

void access_mem(PTE* PT, int virtual_addr) {
    int page_num = virtual_addr / PS;
    int offset = virtual_addr % PS;
    PTE page = PT[page_num];
    if (!page.valid) {
        handle_PF(PT, page_num);
    }
    int physical_addr = page.frame * PS + offset;
    printf("Accessing virtual address %d -> Physical address %d\n", virtual_addr, physical_addr);
}

int main() {
    srand(time(NULL));
    PTE* PT = init_PT();
    int virtual_addr;
    printf("Enter virtual address (0 - 32767): ");
    scanf("%d", &virtual_addr);
    access_mem(PT, virtual_addr);
    free(PT);
    return 0;
}

