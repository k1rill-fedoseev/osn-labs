#include <stdio.h>
#include <unistd.h>

int main() {
    int n;
    if ((n = fork()) == 0) {
        printf("Hello from child [PID - %d]\n", getpid());
    } else {
        printf("Hello from parent [PID - %d]\n", getpid());
    }
}