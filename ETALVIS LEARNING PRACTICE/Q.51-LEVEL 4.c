#include<stdio.h>
#include<string.h>
int main()
{
    char stre[50];
    char ch;
    int i=0;
    printf("Enter the string : ");
    scanf("%s",stre);
    printf("Enter the character that you want to find : ");
    scanf(" %c",&ch);
    while(stre[i] != '\0')
    {

        if(stre[i]==ch)
        {
            printf("%d,",(i+1));
        }
        i++;
    }

}
