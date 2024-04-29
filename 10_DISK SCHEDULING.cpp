#include <stdio.h>
#include <stdlib.h>

#define NUM_REQUESTS 20
#define DISK_SIZE 200
#define START_POSITION 100

void fcfs(int requests[]) {
    printf("FCFS (First-Come, First-Served):\n");
    printf("Request\tPosition\n");
    for (int i = 0; i < NUM_REQUESTS; i++) {
        printf("%d\t%d\n", i + 1, requests[i]);
    }
}

void scan(int requests[]) {
    printf("\nSCAN:\n");
    printf("Request\tPosition\n");

    int sorted_requests[NUM_REQUESTS];
    for (int i = 0; i < NUM_REQUESTS; i++) {
        sorted_requests[i] = requests[i];
    }
    for (int i = 0; i < NUM_REQUESTS - 1; i++) {
        for (int j = 0; j < NUM_REQUESTS - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    int head_movement = 0;
    int current_position = START_POSITION;

    while (current_position >= 0) {
        for (int i = 0; i < NUM_REQUESTS; i++) {
            if (current_position == sorted_requests[i]) {
                printf("%d\t%d\n", i + 1, current_position);
                head_movement++;
            }
        }
        current_position--;
    }

    current_position = START_POSITION + 1;
    while (current_position <= DISK_SIZE) {
        for (int i = 0; i < NUM_REQUESTS; i++) {
            if (current_position == sorted_requests[i]) {
                printf("%d\t%d\n", i + 1, current_position);
                head_movement++;
            }
        }
        current_position++;
    }

    printf("Total head movement: %d\n", head_movement);
}

void c_scan(int requests[]) {
    printf("\nC-SCAN:\n");
    printf("Request\tPosition\n");

    int sorted_requests[NUM_REQUESTS];
    for (int i = 0; i < NUM_REQUESTS; i++) {
        sorted_requests[i] = requests[i];
    }
    for (int i = 0; i < NUM_REQUESTS - 1; i++) {
        for (int j = 0; j < NUM_REQUESTS - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    int head_movement = 0;
    int current_position = START_POSITION;

    while (current_position <= DISK_SIZE) {
        for (int i = 0; i < NUM_REQUESTS; i++) {
            if (current_position == sorted_requests[i]) {
                printf("%d\t%d\n", i + 1, current_position);
                head_movement++;
            }
        }
        current_position++;
    }

    current_position = 0;
    while (current_position < START_POSITION) {
        for (int i = 0; i < NUM_REQUESTS; i++) {
            if (current_position == sorted_requests[i]) {
                printf("%d\t%d\n", i + 1, current_position);
                head_movement++;
            }
        }
        current_position++;
    }

    printf("Total head movement: %d\n", head_movement);
}

int main() {
    int requests[NUM_REQUESTS];

    srand(time(NULL));
    for (int i = 0; i < NUM_REQUESTS; i++) {
        requests[i] = rand() % (DISK_SIZE + 1);
    }

    fcfs(requests);
    scan(requests);
    c_scan(requests);

    return 0;
}

