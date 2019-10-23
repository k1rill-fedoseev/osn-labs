#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dirp = opendir("./tmp");
    if (dirp == NULL) { 
        return -1; 
    }
    struct dirent *dp;

    ino_t A[255];
    char *names[255];
    int i = 0;

    while ((dp = readdir(dirp)) != NULL) {
        A[i] = dp->d_ino;
        names[i++] = dp->d_name;
    }
    for (int j = 0; j < i; j++) {
        int f = 0;
        for (int k = j + 1; k < i; k++) {
            if (A[k] == A[j] && A[k] != -1) {
                if (f == 0) {
                    printf("Found linked file, existing links: %s, %s", names[j], names[k]);
                    f = 1;
                }
                else {
                    printf(", %s", names[k]);
                }
                A[k] = -1;
            }
        }
        if (f) {
            printf("\n");
        }
    }
    closedir(dirp);
    return 0;
}