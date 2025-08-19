/*Question: Write a program to print the total number of single digit Prime numbers
Assume 0 & 1 are not Prime.
Answer : 4*/

#include<stdio.h>
int i,count=0,flag=0,x;
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

        }
        flag=0;
}
printf("The total number of single digit Prime numbers are :%d",count);
}
