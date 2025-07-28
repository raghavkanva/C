#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

void getnumbers(char *num1, char *num2);

void addnumbers(char * n1p, char * n2p, char *result);

int main(void) {
    char result[51] = {0};
    char n1[50];
    char n2[50];
    char *n1p = n1;
    char *n2p = n2;
    getnumbers(n1p, n2p);
    addnumbers(n1p,n2p,result);
    printf("The result is %s: ",result);
    return 0;
}

void getnumbers(char *num1, char *num2) {
    strcpy(num1, "48252857586735723582352572582752586252592525592458");
    strcpy(num2, "58266985624857325982356935875642579843563401461402");
}
void addnumbers(char * n1, char * n2, char *result) {
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
        strcpy(result,sum);
    } else {
        strcpy(result,sum+1);
    }
}