#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter Number : ");
    scanf("%d",&x);
    int a, tens;
    tens=((x%100)/10);
    a=tens%2;
    y=x-(a*5);
    printf("Result=%d",y);
}
