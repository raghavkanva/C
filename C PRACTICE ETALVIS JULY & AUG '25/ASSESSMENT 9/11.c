// File: 11.c | System: Dell | Time: 07:09 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0707:09 AM.09 
//


#include <stdio.h>
int reverse(int n);
int main(void) {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d",&arr[i]);
        arr[i] = reverse(arr[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

