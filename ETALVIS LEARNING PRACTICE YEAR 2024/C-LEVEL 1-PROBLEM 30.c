#include<stdio.h>
int main ()
{
int x,y;
printf ("Enter Number : ");
scanf("%d",&x);
// Your Code Here
int tens, hundreds,sum;
tens=((x%100)/10);
printf("1: %d\n",tens);
hundreds=((x/100)%10);
printf("2: %d\n",hundreds);
sum=tens+hundreds;
printf("3: %d\n",sum);
if((sum==10) && (((tens>7) || (hundreds>7))))
{
    printf("Success !");
}

else
{
    printf("Failure");
}
}
