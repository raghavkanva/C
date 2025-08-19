/*Question: Write a program to print the total number of TWO digit odd numbers.
Answer : 45*/

#include<stdio.h>
int count=0,x=1;
int main()
{
    for(x=10;x<=99;x++)
    {
        if(x%2!=0)
        {
            count++;
        }
    }
    printf("No Of occurences of total number of TWO digit odd numbers : %d",count);
}
