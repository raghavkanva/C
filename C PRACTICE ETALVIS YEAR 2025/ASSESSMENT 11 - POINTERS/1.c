// File: 1.c | System: Dell | Time: 06:12 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:12 AM.12 
//


#include <stdio.h>

int main(void) {
    int num;
    int *numPointer;
    printf("Enter a number: ");
    scanf("%d", &num);
    numPointer = &num;
    *numPointer = 23;
    printf("The value is: %d\n", num);

    return 0;
}
