/*Question: Write a program to print the sum of all TWO digit odd numbers
Answer : 2475*/

#include<stdio.h>
int count=0,x=1;
int sum;
int main()
{
    for(x=10;x<=99;x++)
    {
        if(x%2!=0)
        {
            count++;
            sum+=x;
        }
    }
    printf("Sum of occurences of total number of TWO digit odd numbers : %d",sum);
}

