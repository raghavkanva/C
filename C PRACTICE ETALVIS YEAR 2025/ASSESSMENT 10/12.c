// File: 12.c | System: Dell | Time: 06:05 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:05 AM.05 
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
    char arr1[50];
    for (int i = 0; i < 50; i++) {
        arr1[i] = arr[i] + '0';
    }
    arr1[50] = '\0';
    printf("%s",arr1);
    return 0;
}
