#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("%ld bytes, %d\n", sizeof(a), a);
    printf("%ld bytes, %e\n", sizeof(b), b);
    printf("%ld bytes, %e\n", sizeof(c), c);
    return 0;
}