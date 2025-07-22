#include <stdio.h>

int lcm(int a, int b);
int hcf(int a, int b);

int main(void) {
    int x = 24, y = 36,z=54;  // You likely used 0 accidentally
    if (x == 0 || y == 0 || z == 0) {
        printf("LCM is not defined for zero.\n");
        return 1;
    }
    printf("The LCM of the two numbers is: %d\n", lcm(x, y));
    printf("The LCM of three numbers are : %d\n",(lcm(lcm(x,y),z)));
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
