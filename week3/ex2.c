#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    int arr[] = {2, 4, 6, 3, 7, 8, 9, 0, 1, 5};
    bubble_sort(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}