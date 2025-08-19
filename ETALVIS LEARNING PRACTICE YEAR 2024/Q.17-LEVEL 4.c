/*Question: Write a program to print the sum of all single digit odd numbers
Answer : 25*/

#include<stdio.h>
int count=0,x=1;
int sum;
int main()
{
    for(x=1;x<=10;x++)
    {
        if(x%2!=0)
        {
            count++;
            sum+=x;
        }
    }
    printf("Sum of occurences of total number of single digit odd numbers : %d",sum);
}
