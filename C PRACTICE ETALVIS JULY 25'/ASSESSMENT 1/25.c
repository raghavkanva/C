#include <stdio.h>
#include "../sum.h"
int main() {
    int x, y;
    printf("Enter a 3-Digit Number : ");
    scanf("%d", &x);
    if (sum(x)<10) printf("%d\n", sum(x));
    else {
       y = sum(x);
        while (y/10!=0) {
            y = sum(y);
        }
        printf("%d\n", y);
   }
    return 0;
}