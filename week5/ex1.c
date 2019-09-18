#include <stdio.h>
#include <pthread.h>

#define N 10

void print(int x) {
    printf("Hello from thread, number %d\n", x);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;

    for (int i = 0; i < N; i++) {
        pthread_create(&tid, NULL, &print, i);

        pthread_join(tid, NULL);
    }
}