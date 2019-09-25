#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void action(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    int childId;

    if ((childId = fork()) == 0) {
        //child 
        while (1) {
            sleep(1);
            printf("I am alive\n");
        }
    }
    else {
        sleep(10);
        kill(childId, SIGTERM);
    }

    return 0;
}

/*
I am alive
I am alive
I am alive
I am alive
I am alive
I am alive
I am alive
I am alive
I am alive
*/