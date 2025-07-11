#include<stdio.h>
#include<string.h>
int main()
{
    char num1[50];
    char num2[50];
    printf("Enter the first number");
    scanf("%d",&num1);
    printf("Enter the second number :");
    scanf("%d",&num2);
    int len1,len2;
    len1=strlen(num1);
    printf("%d\n",len1);
    len2=strlen(num2);
    printf("%d\n",len2);
    int big;
    if(len1<len2)
    {
        big=len2;
    }
    if(len1>len2)
    {
        big=len1;
    }
    printf("%d\n",big);
    int prod[50];
    int i=0,carry=0;
    for(i=big-1;i>=0;i--)
    {
        prod[i]=((num1[i]-48)*(num2[i]-48))+carry;
        printf("%d\n",(num1[i]-48));
        carry=prod[i]/10;
        prod[i]=prod[i]%10;
    }
    for(i=0;i<big;i++)
    {
        printf("%d",prod[i]);
    }
}
