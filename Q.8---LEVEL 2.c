#include<stdio.h>
int main()
{
    int x;
    x=10;
    loop: if ((x>10)&&(x%2==0)&&(x<100))
    {
        int one, ten, sum;
        one=x%10;
        ten=x/10;
        sum=one+ten;
        if(sum==6)
        {
            printf("%d \n",x);
        }

    }
    x+=1;
    goto loop;
}



