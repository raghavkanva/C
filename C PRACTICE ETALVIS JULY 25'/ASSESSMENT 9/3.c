// File: 3.c | System: Dell | Time: 06:44 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0606:44 AM.44 
//


#include <limits.h>
#include <stdio.h>

int main(void) {
    int arr[5];
    int smallest = INT_MAX;
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d",&arr[i]);
        if (arr[i] < smallest) smallest = arr[i];
    }
    printf("The smallest of all numbers are %d",smallest);
    return 0;
}
