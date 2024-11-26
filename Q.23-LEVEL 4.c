/*Question: Write a program to print the sum of single digit Prime numbers
Answer: 17*/

#include<stdio.h>
int i,count=0,flag=0,x,sum;
int main()
{
for(i=2;i<=9;i++)
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
printf("The sum of total number of single digit Prime numbers are :%d",sum);
}
