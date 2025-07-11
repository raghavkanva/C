#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    printf("Enter the sentence: ");
    gets(str);
    int count=0,i=0;
    while(str[i]!='\0')
    {
        if(str[i]==32)
        {
            count++;
        }
        i++;
    }
    printf("The total words in this sentence is : %d",count);
}
