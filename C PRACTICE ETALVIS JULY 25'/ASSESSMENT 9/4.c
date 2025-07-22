// File: 4.c | System: Dell | Time: 06:46 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0606:46 AM.46 
//


#include <limits.h>
#include <stdio.h>

int main(void) {
    int arr[5];
    int biggest = INT_MIN;
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d",&arr[i]);
        if (arr[i] > biggest) biggest = arr[i];
    }
    printf("The biggest of all numbers are %d",biggest);
    return 0;
}