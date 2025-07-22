#include <stdio.h>

int lcm(int a, int b);
int hcf(int a, int b);

int main(void) {
    int x = 24, y = 36;  // You likely used 0 accidentally
    if (x == 0 || y == 0) {
        printf("LCM is not defined for zero.\n");
        return 1;
    }
    printf("The LCM of the two numbers is: %d\n", lcm(x, y));
    return 0;
}

int lcm(int a, int b) {
    int h = hcf(a, b);
    if (h == 0) return 0;
    return (a * b) / h;
}

int hcf(int a, int b) {
    if (b == 0) return a;
    return hcf(b, a % b);
}
