// File: 1.c | System: Dell | Time: 06:41 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0606:41 AM.41 
//


#include <stdio.h>

int main(void) {
    int arr[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    printf("The sum of all numbers are %d",sum);
    return 0;
}
