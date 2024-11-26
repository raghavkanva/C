#include<stdio.h>
int main()
{
    int arrnum[]={1,2,3,3,2,1};
    char str[50];
    int i=0;
    for(i=0;i<6;i++)
    {
        str[i]=(arrnum[i]+48);
    }
    printf("%s",str);
}
