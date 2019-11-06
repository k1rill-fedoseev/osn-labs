#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char c;
    int *fds = malloc(argc * sizeof(int));
    for (int i = 1; i < argc; i++) {
        fds[i] = open(argv[i], O_WRONLY | O_CREAT, S_IRWXU);
    }
    while (read(0, &c, 1)) {
        for(int i = 1; i < argc; i++) {
            write(fds[i], &c, 1);
        }
        write(1, &c, 1);
    }
    for (int i = 1; i < argc; i++) {
        close(fds[i]);
    }
    free(fds);
}