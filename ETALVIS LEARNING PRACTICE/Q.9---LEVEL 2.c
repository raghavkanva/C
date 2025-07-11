#include<stdio.h>
int main()
{
    int x;
    x=15;
    int sum=0;
    loop: if (x<100)
    {
        sum+=x;
        x+=10;
        goto loop;
    }
    printf("The sum is : %d",sum);
}



