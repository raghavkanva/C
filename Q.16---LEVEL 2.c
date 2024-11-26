#include<stdio.h>
int num ,i;
int flag=0;
int main()
{
    printf("Enter the number :");
    scanf("%d",&num);
    for(i=2; i<num; i++)
    {
        if(num%i==0)
        {
            flag=1;
            printf("It is not a prime !");
            break;
        }
    }
    if(flag==0)
    {
        printf("It is a prime !");
    }
}
