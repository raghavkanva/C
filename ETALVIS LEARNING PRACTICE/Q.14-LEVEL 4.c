/*Question: Write a program to print the total number of single digit odd
numbers
Answer - 5*/

#include<stdio.h>
int count=0,x=1;
int main()
{
    for(x=1;x<=10;x++)
    {
        if(x%2!=0)
        {
            count++;
        }
    }
    printf("No Of occurences of total number of single digit odd numbers : %d",count);
}
