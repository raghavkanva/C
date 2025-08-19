// File: 6.c | System: Dell | Time: 06:53 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0606:53 AM.53 
//


#include <stdio.h>

void sort(int arr[],int n);
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d",&arr[i]);
    }
    sort(arr,5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void sort(int arr[],int n) {
    int temp = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j=0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
