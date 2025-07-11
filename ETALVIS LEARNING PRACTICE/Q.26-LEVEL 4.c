/*Question: Print the smallest Three digit prime number
Answer: 101*/

#include<stdio.h>
int i,flag=0,x,s;
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
            s=i;
            break;
        }
        flag=0;
}
printf("The smallest triple digit Prime number is :%d",s);
}

