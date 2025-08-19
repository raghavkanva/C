#include <stdio.h>

void add(char(* num1)[51], char(* num2)[51], char(* res)[52]);

int main(void) {
    char num1[51]="54786016094864938937598464697596017249486948069856";
    char num2[51]="14786016094864938937598464697596017249486948469852";
    char result[52] = {0};
    add(&num1,&num2,&result);
    printf("%s",result);
    return 0;
}
void add(char(* num1)[51], char(* num2)[51],char (*res)[52]) {
    int sum = 0;
    int carry = 0;
    (*res)[51] = '\0';
    for(int i = 49; i >= 0; i--) {
        sum = carry + *(num1 + i)-48 + (*num2)[i]-48;
        sum %= 10;
        (*res)[i+1] =sum + '0';
        carry = sum / 10;
    }
    if (carry)
        (*res)[0] = carry + '0';
    else
        (*res)[0] = '0';
}