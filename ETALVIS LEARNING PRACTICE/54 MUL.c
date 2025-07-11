#include<stdio.h>
#include<string.h>
int main()
{
    char num1[6],num2[6];
    char res[6],temp[6];
    int i=0,j=0,k=0;
    int c=0,prod=0,d=0;
    int len1=strlen(num1);
    int len2=strlen(num2);
    int big=max(len1,len2);
    printf("Biggest Number : %d",big);
}
