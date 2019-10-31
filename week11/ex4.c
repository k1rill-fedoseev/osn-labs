#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>

int main () {
    int fd = open("./ex1.txt", O_RDWR, 0x0777);
    int fd2 = open("./ex1.memcpy.txt", O_RDWR, 0x0777);
    struct stat *buf = malloc(sizeof(struct stat));
    fstat(fd, buf);
    int len = buf->st_size;
    ftruncate(fd2, len);
    close(fd2);
    fd2 = open("./ex1.memcpy.txt", O_RDWR);
    char *str = mmap(NULL, len, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    char *str2 = mmap(NULL, len, PROT_WRITE | PROT_READ, MAP_SHARED, fd2, 0);
    memcpy(str2, str, len);
    close(fd2);
    close(fd);
    free(buf);
    return 0;
}