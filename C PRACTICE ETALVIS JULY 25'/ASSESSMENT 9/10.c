// File: 10.c | System: Dell | Time: 07:08 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0707:08 AM.08 
//


#include <stdio.h>

#include "../isPrime.h"

int main(void) {
    int arr[5];
    int new[5]={0};
    int j=0;
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d",&arr[i]);
        if (isPrime(arr[i])) {
            new[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", new[i]);
    }
    return 0;
}
