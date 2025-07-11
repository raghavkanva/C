/*Question: write a program to print the total number of THREE digit odd numbers
Answer : 450*/

#include<stdio.h>
int count=0,x=1;
int main()
{
    for(x=100;x<=999;x++)
    {
        if(x%2!=0)
        {
            count++;
        }
    }
    printf("No Of occurences of total number of THREE digit odd numbers : %d",count);
}
