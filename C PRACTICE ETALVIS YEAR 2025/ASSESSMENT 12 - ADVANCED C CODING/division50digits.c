#include <stdint.h>
#include <stdio.h>
#include <string.h>

void get_numbers(char num1[51], char num2[51]) {
    strcpy(num1, "12345678");
    strcpy(num2, "10");
}

int check_if_bigger(char *num1, char *num2) {
    int l1 = strlen(num1);
    int l2 = strlen(num2);

    if (l1 > l2) return 1;
    if (l1 < l2) return 0;

    while (*num1 && *num2) {
        if (*num1 > *num2) return 1;
        if (*num1 < *num2) return 0;
        num1++;
        num2++;
    }
    return 1;
}

void subtract(char *num1, char *num2, char *result) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int k = i + 1;
    int borrow = 0;
    result[k] = '\0';

    while (i >= 0) {
        int digit1 = num1[i] - '0';
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        digit1 -= borrow;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[--k] = (digit1 - digit2) + '0';

        i--;
        j--;
    }
    int start = 0;
    while (result[start] == '0' && result[start + 1] != '\0') start++;
    if (start > 0) {
        int index = 0;
        while (result[start] != '\0') {
            result[index++] = result[start++];
        }
        result[index] = '\0';
    }
}

void divide(char divisor[51], char dividend[51], char quotient[51]) {
    //Initialise an array to store the current part that has been divided
    char temp_dividend[51] = {0};
    int len = strlen(dividend); //Variable to store the length of the dividend

    //To store the result of each division process , initialise a variable to track the index
    int q = 0;

    //Traverse the array using for loop
    for (int i = 0; i < len; i++) {
        int len_temp_dividend = strlen(temp_dividend);
        temp_dividend[len_temp_dividend] = dividend[i];
        temp_dividend[len_temp_dividend + 1] = '\0';// To Terminate the string

        //Terminate the leading zeros in the dividend
        uint8_t index = 0;
        while (temp_dividend[index] == '0' &&temp_dividend[++index] != '\0') {
            memmove(temp_dividend, temp_dividend + 1, len_temp_dividend - 1 - index);
        }

        //Division Process
        int count = 0; //To track the count of how many times a numbers gets divided
        char temp[51] = {0};
        while (check_if_bigger(temp_dividend, divisor)) {
            subtract(temp_dividend, divisor, temp);
            strcpy(temp_dividend, temp);
            count++;
        }
        quotient[q++] = count + '0';
    }
}

void print(char quotient[51]) {
    printf("%s", quotient);
}

int main() {
    char divisor[51] = {0};
    char dividend[51] = {0};
    get_numbers(dividend, divisor);
    char quotient[51] = {0};
    divide(divisor, dividend, quotient);
    print(quotient);
    return 0;
}