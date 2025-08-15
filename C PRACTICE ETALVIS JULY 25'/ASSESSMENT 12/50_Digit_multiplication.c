#include<stdio.h>
#include <string.h>

void getnumbers(char *num1, char *num2);
void multiply(char *num1, char *num2, char *result);
void print(char *result);

void main() {
    char num1[51] = "54786016094864938937598464697596017249486948069856";
    char num2[51] = "14786016094864938937598464697596017249486948469852";
    char result[101] = {0};
    multiply(num1,num2,result);
    print(result);
}

void multiply(char *num1, char *num2, char *result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int temp[102] = {0};

    //Multiply Each Digit
    for (int i = len1 - 1; i >= 0; i--) {
        int n1 = num1[i] - '0';
        for (int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            temp[i + j + 1] += n1 * n2;
        }
    }

    //Handle the carry
    for (int i = len1 + len2 - 1; i > 0; i--) {
        if (temp[i] >= 10) {
            temp[i - 1] += temp[i]/10;
            temp[i] %= 10;
        }
    }

    //convert array to string
    for (int i = 0; i < len1 + len2; i++) {
        result[i] = temp[i] + '0';
    }
    result[100] = '\0';
}
void print(char *result) {
    printf("%s",result);
}
