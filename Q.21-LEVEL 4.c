/*Question: Write a program to print the total number of TWO digit Prime numbers
Answer : 21*/

#include<stdio.h>
int i,count=0,flag=0,x;
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

        }
        flag=0;
}
printf("The total number of Double digit Prime numbers are :%d",count);
}
