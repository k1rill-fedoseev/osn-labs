#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUF 50

int main() {
    int p[2];

    pipe(p);

    if (fork() == 0) {
        //child 
        char s[BUF] = "";
        read(p[0], s, BUF);
        printf("Read from pipe in child: %s\n", s);
    }
    else {
        char s[BUF] = "Hello world";
        printf("Writing to pipe in parent: %s\n", s);

        write(p[1], s, BUF);
    }

    return 0;
}

/*
Writing to pipe in parent: Hello world
Read from pipe in child: Hello world
*/