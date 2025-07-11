#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter Number : ");
    scanf("%d",&x);
    int a, ten, hun;
    ten=((x%100)/10);
    hun=(x/100)%10;
    a=(ten==hun);
    y=x-(a*5);
    printf("Result=%d",y);
}
