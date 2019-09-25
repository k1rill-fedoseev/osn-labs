#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void action(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    struct sigaction handler;
    handler.sa_handler = &action;
    sigaction(2, &handler, NULL);

    while (1) {}

    return 0;
}

/*
Received signal 2
*/