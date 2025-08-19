/*Question: Total number of prime numbers below 1,000,000 have the sum of their digits
equal to 14?
Example: 59. 5 + 9 = 14*/

#include<stdio.h>
int sod(int num);
int main()
{
    int i,j,count=0,sum=0;
    int flag=0;
    for(i=2;i<=1000000;i++)
    {
        for(j=2;j<(i/2);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        sum=sod(i);
        if((flag==0)&&(sum==14))
        {
            count++;
        }
        flag=0;
    }
    printf("Prime numbers with sum of 14 : %d",count);
}
int sod(int num)
{
    int sum=0;
    while(num!=0)
    {
        sum+=(num%10);
        num/=10;
    }
    return sum;
}

