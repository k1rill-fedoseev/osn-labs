#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main () {
    int fd = open("./ex1.txt", O_RDWR);
    char *s = "This is a nice day";
    char *str = mmap(NULL, strlen(s), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    memcpy(str, s, strlen(s));
    ftruncate(fd,strlen(s));
    close(fd);
    //int a = munmap(str, strlen(s));
    return 0;
}