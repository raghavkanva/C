// File: 2.c | System: Dell | Time: 06:14 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:14 AM.14 
//


#include <stdio.h>

int main(void) {
    int arr[50] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    increment(arr);
    for (int i = 0; i < 50; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
void increment(int *arr) {
    for (int i = 0; i < 50; i++) {
        *(arr + i) = *(arr + i) + 1;
    }
}
