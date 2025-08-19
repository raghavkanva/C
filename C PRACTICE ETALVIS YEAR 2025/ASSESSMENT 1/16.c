#include <stdio.h>
#include "../digit.h"
int main() {
    int x, y;
    printf("Enter a 4-Digit Number : ");
    scanf("%d", &x);
    y = digitExtract(x,2)*1000 + digitExtract(x,3)*100 + x%100;
    printf("%d\n", y);
}