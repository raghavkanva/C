#include <stdio.h>
#include <string.h>

int main(void) {
    char n1[50] = "34827593018237465091827364509182736450918273645091";
    char n2[50] = "92736450918273645091827364509182736450918273645091";
    char sum[51] = {0};
    int carry = 0;
    for (int i = 49; i >= 0; i--) {
        int digit1 = n1[i] - '0';
        int digit2 = n2[i] - '0';
        int total = digit1 + digit2 + carry;
        sum[i+1] = (total % 10) + '0';
        carry = total / 10;
    }
    sum[0] = carry ? carry + '0' : ' ';
    if (carry) {
        printf("Sum: %s\n", sum);
    } else {
        printf("Sum: %s\n", sum + 1);
    }
    return 0;
}