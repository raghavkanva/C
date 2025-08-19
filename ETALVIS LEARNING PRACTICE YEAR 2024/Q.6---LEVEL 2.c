#include<stdio.h>
int main()
{
    int x;
    x=11;
    loop: if (x<20)
    {
        printf("%d \n",x);
        x+=2;
        goto loop;
    }
}


