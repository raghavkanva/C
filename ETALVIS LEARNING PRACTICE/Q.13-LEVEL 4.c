/*Question: Get a number from the user and print the sum of all digits.
Example: User Enters “123456”
Answer - 21*/

#include<stdio.h>
int sum=0,x;
int main()
{
    printf("Enter the number : ");
    scanf("%d",&x);
    while(x!=0)
    {
        sum+=x%10;
        x/=10;
    }
    printf("The Sum of the digits is : %d",sum);
}
