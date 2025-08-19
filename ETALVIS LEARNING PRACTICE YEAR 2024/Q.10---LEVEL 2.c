#include<stdio.h>
int main()
{
    int x;
    x=71;
    int sum=0;
    loop: if (x<80)
    {
        sum+=x;
        x+=2;
        goto loop;
    }
    printf("The sum is : %d",sum);
}



