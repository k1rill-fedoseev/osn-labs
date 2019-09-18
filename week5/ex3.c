#include <stdio.h>
#include <pthread.h>

int queue[100];
int count = 0;

int consumerSleep = 0;
int producerSleep = 0;

void consumer() {
    int i = 0;
    while(1) {
        while(consumerSleep) {}
        
        if (count) {
            count--;
            producerSleep = 0;
            queue[i % 100] = i++;
        }
        else {
            consumerSleep = 1;
        }
    }
}

void producer() {
    int i = 0;
    while(1) {
        while(producerSleep) {}

        if (i % 1000 == 0)
            printf("%d\n", count);

        if (count < 100) {
            count++;
            consumerSleep = 0;
            queue[i % 100] = i++;
        }
        else {
            producerSleep = 1;
        }
    }
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, &producer, NULL);
    pthread_create(&tid, NULL, &consumer, NULL);

    pthread_join(tid, NULL);
}