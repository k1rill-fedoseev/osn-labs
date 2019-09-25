#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h> 
#include <sys/wait.h>

#define BUF 50

int main() {
    int childId1, childId2;
    int p[2];
    pipe(p);

    if ((childId1 = fork()) == 0) {
        //child 1
        printf("Child 1 forked\n");
        char s[BUF];
        read(p[0], s, BUF);
        int pid;
        sscanf(s, "%d", &pid);
        printf("Read child 2 id from pipe: %d\n", pid);
        sleep(2);
        printf("Killing child 2\n");
        kill(pid, SIGSTOP);
        printf("Exiting child 1\n");
        exit(0);
    }
    else {
        if ((childId2 = fork()) == 0) {
            //child 2 
            printf("Child 2 forked\n");
            while (1) {
                printf("Child 2 is alive\n");
                sleep(1);
            }
        }
        else {
            // main process
            char s[BUF];
            sprintf(s, "%d", childId2);
            printf("Sending child 2 pid to pipe: %d\n", childId2);
            write(p[1], s, BUF);

            printf("Waiting for child 2 to change state\n");
            waitpid(childId2, NULL, WUNTRACED);
            printf("Wait finished\n");
        }
    }

    return 0;
}

/*
Sending child 2 pid to pipe: 44839
Waiting for child 2 to change state
Child 1 forked
Read child 2 id from pipe: 44839
Child 2 forked
Child 2 is alive
Child 2 is alive
Killing child 2
Exiting child 1
Wait finished
*/