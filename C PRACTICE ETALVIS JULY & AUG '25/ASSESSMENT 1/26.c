#include <stdio.h>
int main() {
    int x, y;
    printf("Enter a 3-Digit Number : ");
    scanf("%d", &x);
    y = (x/10)*10;
    printf("%d\n", y);
}