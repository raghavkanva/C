#include<stdio.h>
int main()
{
    int count=0;
    char s[10];
    printf("Enter the string :");
    scanf("%s",&s);
    int i=0;
    while(s[i] != 0)
    {
        count++;
        i++;
    }
    printf("The length of the string is : %d",count);
}
