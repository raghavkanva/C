/*Question: Print the Largest Four digit prime number
Answer: 9973*/

#include<stdio.h>
int i,flag=0,x,s;
int main()
{
for(i=10000;i<=99999;i++)
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

        }
        flag=0;
}
printf("The Largest four digit Prime number is :%d",s);
}



