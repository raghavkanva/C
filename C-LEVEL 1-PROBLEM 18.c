#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter Number : ");
    scanf("%d",&x);
    y=(10+(x%10));
    printf("Result=%d",y);
}
