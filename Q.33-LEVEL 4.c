/*Question: Print the total number of non-decreasing numbers from 1000 to 9999.Non
decreasing numbers have individual digits that do not have a decreasing order
from left to right.
(For e.g.: 1234 is a non-decreasing number where as 2134 is not)*/

#include<stdio.h>
int check(int n);
int checked=0;
int main()
{
    int i;
    int count=0;
    for(i=1000;i<=9999;i++)
    {
        check(i);
        if(checked==0)
        {
            count++;
            printf("%d\n",i);
        }
    }
    printf("Total Count : %d",count);
}
int check(int n)
{
    int dig,cond=9,flag=0;
    while(n!=0)
    {

        dig=(n%10);

        if(dig<=cond)
        {
            flag=0;
        }
        else
        {
            flag=1;
            break;
        }
        cond=dig;
        n/=10;
    }
    checked=flag;
    return 0;
}
