#include<stdio.h>
int add_2(int num);
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("The result is : %d",add_2(num));
}
int add_2(num)
{
    int res=num+2;
    return res;
}
