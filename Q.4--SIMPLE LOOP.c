#include<stdio.h>
int main()
{
    int x;
    x=5;
    int sum=0;
    loop: if (x>0)
    {
        sum+=x;
        x-=1;
        goto loop;
    }
    printf("The Sum is : %d",sum);
}

