#include <stdio.h>

void figure1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 2 * n; j++) {
            putchar(j <= n + i && j >= n - i ? '*' : ' ');
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    int n;
    sscanf(argv[1], "%d", &n);
    figure1(n);
    return 0;
}