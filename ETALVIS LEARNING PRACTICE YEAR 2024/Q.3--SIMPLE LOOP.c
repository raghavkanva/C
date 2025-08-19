#include<stdio.h>
int main()
{
    int x;
    x=1;
    int sum=0;
    loop: if (x<6)
    {
        sum+=x;
        x+=1;
        goto loop;
    }
    printf("The sum is : %d",sum);
}

