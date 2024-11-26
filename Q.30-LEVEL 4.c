/*Question: Print the Largest eight-digit prime number
Answer: 99999989*/

#include<stdio.h>
int flag=0,s;
long int i;
long int x;
int main()
{
for(i=10000000;i<=99999999;i++)
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



