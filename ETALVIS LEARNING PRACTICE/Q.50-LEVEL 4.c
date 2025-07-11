#include<stdio.h>
#include<string.h>
int main()
{
    char a[50];
    char b[50];
    printf("Enter 1st Number : ");
    scanf("%s",&a);
    printf("Enter 2nd Number : ");
    scanf("%s",&b);
    int len1=strlen(a);
    int len2=strlen(b);
    int i=0,j=0;
    int carry=0;
    for(i=0,j=0;i<len1,j<len2;i++,j++)
    {

        int res=((a[i]-48)+(b[i]-48)+carry);
        printf("%d",(res));
        carry=(res/10);

    }
}
