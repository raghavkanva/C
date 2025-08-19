#include <stdio.h>
#include <string.h>

void subtract(char *num1, char *num2, char *result);
void print(char *result);

void main(void) {
    char num1[51] = "54786016094864938937598464697596017249486948069856";
    char num2[51] = "14786016094864938937598464697596017249486948469852";
    char result[51] = {0};
    subtract(num1,num2,result);
}
void subtract(char *num1, char *num2, char *result) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int k = i+1;
    int borrow = 0;
    result[k] = '\0';

    while (i >= 0) {
        int digit1 = num1[i] - '0';
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        digit1 -= borrow;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        }
        else borrow = 0;

        result[--k] = (digit1 - digit2) + '0';

        i--;
        j--;
    }
    //Remove Leading Zeros Without Memmove
    int start = 0;
    while (result[start] == '0' && result[start +1] != '\0') start++;

    //Shift Manually
    if (start > 0) {
        int index = 0;
        while (result[start] != '\0') {
            result[index++] = result[start++];
        }
        result[index] = '\0';
    }
    print(result);
}

void print(char *result) {
    printf("%s", result);
}
