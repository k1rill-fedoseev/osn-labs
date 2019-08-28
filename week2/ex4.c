#include <stdio.h>

void swap(int *pa, int *pb) {
    *pb = *pb - *pa;
    *pa = *pb + *pa;
    *pb = *pa - *pb;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}