#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    scanf("%d", &N);

    int *arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
}

/*
20
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
*/