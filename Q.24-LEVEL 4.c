/*Question: Program to print the sum of all TWO digit Prime numbers
Answer: 1043*/

#include<stdio.h>
int i,count=0,flag=0,x,sum;
int main()
{
for(i=10;i<=99;i++)
{
    for(x=2;x<=(i/2);x++)
    {
        if(i%x==0)
        {
            flag=1;
        }
    }
    if(flag==0)
        {
            count++;
            sum+=i;

        }
        flag=0;
}
printf("The sum of total number of double digit Prime numbers are :%d",sum);
}
