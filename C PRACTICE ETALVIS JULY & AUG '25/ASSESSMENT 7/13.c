// File: 13.c | System: Dell | Time: 06:01 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0606:01 AM.01 
//


#include <stdio.h>

#include "../digit.h"

int main(void) {
    int x,y=0;//Initialisation of y is important

    printf("Enter the number : ");
    scanf("%d", &x);
    int len = countDigit(x)-1;
    for (int i = len; i >= 0; i--) {
        y += (x % 10)*pow(10,i);
        x = x / 10;
    }
    printf("The reversed number is : %d", y);
    return 0;
}
