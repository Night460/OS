#include <stdio.h>

#define NUM_FRAMES 3

int main() {
    int frames[NUM_FRAMES];
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int num_pages = sizeof(pages) / sizeof(pages[0]);
    int num_faults = 0;
    int frame_index = 0;

   
    for (int i = 0; i < NUM_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Page Reference String: ");
    for (int i = 0; i < num_pages; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");

    printf("FIFO Page Replacement Policy\n");
    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in frames
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        // Page fault - replace the oldest page
        if (!found) {
            frames[frame_index] = page;
            frame_index = (frame_index + 1) % NUM_FRAMES;
            num_faults++;

            // Print frames
            printf("Page Fault: %d\nFrames: ", page);
            for (int j = 0; j < NUM_FRAMES; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        } else {
            printf("Page Hit: %d\nFrames: ", page);
            for (int j = 0; j < NUM_FRAMES; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", num_faults);

    return 0;
}

