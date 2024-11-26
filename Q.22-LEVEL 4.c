/*Question: Write a program to print total number of THREE digit Prime numbers
Answer - 143*/

#include<stdio.h>
int i,count=0,flag=0,x;
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

        }
        flag=0;
}
printf("The total number of  Triple digit Prime numbers are :%d",count);
}
