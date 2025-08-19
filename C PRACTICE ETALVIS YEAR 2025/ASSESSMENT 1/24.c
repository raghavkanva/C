#include <stdio.h>
#include "../digit.h"
int main() {
    int x, y;
    printf("Enter a 3-Digit Number : ");
    scanf("%d", &x);
    y = x - ((digitExtract(x,0)%2)&&(digitExtract(x,2)%2))*5;
    printf("%d\n", y);
}