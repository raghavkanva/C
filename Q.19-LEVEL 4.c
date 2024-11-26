/*Question: Write a program to print the sum of all THREE digit odd numbers
Answer : 247500*/

#include<stdio.h>
int count=0,x=1;
int sum;
int main()
{
    for(x=100;x<=999;x++)
    {
        if(x%2!=0)
        {
            count++;
            sum+=x;
        }
    }
    printf("Sum of occurences of total number of THREE digit odd numbers : %d",sum);
}
