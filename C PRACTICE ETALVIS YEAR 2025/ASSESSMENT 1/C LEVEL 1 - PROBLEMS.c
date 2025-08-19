#include<stdio.h>

void main() {
    int x, y;
    printf("Enter the Number : ");
    scanf("%d", &x);
    //1
    y = x + 2;
    printf("Result : %d", y);
    //2
    y = x - 5;
    printf("Result : %d", y);
    //3
    y = x*3;
    printf("Result : %d", y);
    //4
    y = x/6;
    printf("Result : %d", y);
    //5
    y = x%8;
    printf("Result : %d", y);
    //Getting two digit Number
    //6
    int a,b;
    printf("Enter the two-digit Number : ");
    scanf("%d", &a);
    b = a%10;
    printf("Result : %d", b);
    //7
    b = a/10;
    printf("Result : %d", b);
    //3 Digit Number
    int c;
    //20
    printf("Enter the three-digit Number : ");
    scanf("%c", &c);
    y = c-(c%10)+2;
    printf("Result : %d", y);
    //21
    y = c-((c%2)*5);
    printf("Result : %d", y);
    //22
    y = c-((((c-5)%100)/10)%2)*5;
    printf("Result : %d", y);




}
