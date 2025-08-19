// File: 8.c | System: Dell | Time: 07:04 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0707:04 AM.04 
//


#include <stdio.h>

int main(void) {
    int arr[5];
    int new[5]={0};
    int j=0;
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d",&arr[i]);
        if (arr[i] % 2 == 1) {
            new[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", new[i]);
    }
    return 0;
}
