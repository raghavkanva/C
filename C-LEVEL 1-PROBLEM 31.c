#include<stdio.h>
int main ()
{
int x,y;
printf ("Enter Number : ");
scanf("%d",&x);
// Your Code Here
int ones,tens, hundreds,sum;
ones=x%10;
tens=(x/10)%10;
hundreds=x/100;
sum=ones+tens+hundreds;
loop: if(sum<10)
{
    printf("%d",sum);
}

else
{
    int ones1,tens1;
    ones1=x%10;
    tens1=x/10;
    sum=ones1+tens1;
    goto loop;
}
}
