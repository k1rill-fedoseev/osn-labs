#include <stdio.h>
#include <stdlib.h>

void *my_realloc(void *ptr, int prev_size, int size) {
    if (size > 0) {
        void *new = malloc(size);
        for (int i = 0; i < prev_size && i < size; i++) {
            *((char *)new + i) = *((char *)ptr + i);
        }
        free(ptr);
        return new;
    }
    free(ptr);
    return NULL;
}

int main() {
    int N;

    scanf("%d", &N);

    int *arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    arr = my_realloc(arr, N * sizeof(int), 2*N * sizeof(int));

    for (int i = 0; i < 2*N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
}

/*
10
0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 0 0 0 0 
*/