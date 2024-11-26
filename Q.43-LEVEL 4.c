#include<stdio.h>
int main()
{
    char s[10];
    printf("Enter the string :");
    scanf("%s",&s);
    int i=0;
    while(s[i] != 0)
    {
        if((s[i]<48)||(s[i]>57))
        {
            printf("It is not a valid number");
            break;
        }
    }

}

