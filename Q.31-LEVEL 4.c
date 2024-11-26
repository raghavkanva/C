/*Question: Print the number of zeroes you encounter between the numbers 0 to
1000*/

#include<stdio.h>
int zeros_count(int num);
int main()
{
    int i,x,count=0;
    for(i=0;i<=1000;i++)
    {
        x=zeros_count(i);
        count+=x;
    }
    printf("The number of zeroes you encounter between the numbers 0 to 1000 : %d",count);
}
int zeros_count(int num)
{
    int count;
    while(num!=0)
    {
        if((num%10)==0)
        {
            count++;
        }
        num/=10;
    }
    return count;
}
