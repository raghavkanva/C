#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter Number : ");
    scanf("%d",&x);
    int a, ones, hun;
    ones=(x%10);
    hun=(x/100);
    a=(ones==hun);
    y=x-(a*5);
    printf("Result=%d",y);
}
