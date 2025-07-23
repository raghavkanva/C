// File: 3.c | System: Dell | Time: 06:22 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:22 AM.22 
//


#include <stdio.h>

void arrange_ascend(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        *(ptr + i) = i + 1;
    }
}

int main() {
    int arr[5];
    arrange_ascend(arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(ptr + i));
    }
    return 0;
}
