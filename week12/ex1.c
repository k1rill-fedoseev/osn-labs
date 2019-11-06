#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/dev/random", O_RDONLY);
    int out = open("./ex1.txt", O_WRONLY | O_CREAT, S_IRWXU);
    char c[20];
    read(fd, c, 20);
    write(out, c, 20);
    close(fd);
    close(out);
}