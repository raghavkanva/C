#include <stdio.h>
#include "../sum.h"
int main() {
    int x, y;
    printf("Enter a 2-Digit Number : ");
    scanf("%d", &x);
    //Find the sum of the number
    y = x - (sum(x)%2)*5;
    printf("%d\n", y);
}
