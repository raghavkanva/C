/*Question: Program to Print the sum of all THREE digit Prime numbers
Answer : 75067*/

#include<stdio.h>
int i,count=0,flag=0,x,sum;
int main()
{
for(i=100;i<=999;i++)
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
printf("The sum of total number of triple digit Prime numbers are :%d",sum);
}
