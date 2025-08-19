#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter Number : ");
    scanf("%d",&x);
    int a, sum;
    sum=((x/10)+(x%10));
    a=(sum==10);
    y=x-(a*5);
    printf("Result=%d",y);
}
