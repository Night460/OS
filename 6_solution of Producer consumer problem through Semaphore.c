#include <stdio.h> 
#include <stdlib.h> 

int mutex = 1, full = 0, empty = 5, x = 0; 

int wait(int); 
int signal(int); 
void producer(); 
void consumer(); 

int main() { 
    int n; 
    printf("\n1. Producer\n2. Consumer\n3. Exit"); 

    while(1) { 
        printf("\n\nEnter your choice: "); 
        scanf("%d", &n); 

        switch(n) { 
            case 1: 
                if (mutex == 1 && empty != 0) 
                    producer(); 
                else 
                    printf("\nBuffer is Full!"); 
                break; 

            case 2: 
                if (mutex == 1 && full != 0) 
                    consumer(); 
                else 
                    printf("\nBuffer is Empty!"); 
                break; 

            case 3: 
                exit(0); 
                break; 
        } 
    } 

    return 0; 
} 

int wait(int a) { 
    return (--a); 
} 

int signal(int a) { 
    return (++a); 
} 

void producer() { 
    mutex = wait(mutex); 
    full = signal(full); 
    empty = wait(empty); 
    x++; 
    printf("\nProducer produces item %d", x); 
    mutex = signal(mutex); 
} 

void consumer() { 
    mutex = wait(mutex); 
    full = wait(full); 
    empty = signal(empty); 
    printf("\nConsumer consumes item %d", x); 
    x--; 
    mutex = signal(mutex); 
}

