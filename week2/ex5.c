#include <stdio.h>

void figure1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 2 * n; j++) {
            putchar(j <= n + i && j >= n - i ? '*' : ' ');
        }
        putchar('\n');
    }
}

void figure2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

void figure3(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i && j <= n - i; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

void figure4(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    int n;
    sscanf(argv[1], "%d", &n);
    figure1(n);
    putchar('\n');
    figure2(n);
    putchar('\n');
    figure3(n);
    putchar('\n');
    figure4(n);
    putchar('\n');
    return 0;
}