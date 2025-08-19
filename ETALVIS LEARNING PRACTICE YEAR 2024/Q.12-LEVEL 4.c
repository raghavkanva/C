/*Question: Get a number from the user and print the reverse of it.
Example: User Enters “123456”
Answer - 654321*/

#include<stdio.h>
int x,y=0;
int main()
{
    printf("Enter a number: ");
    scanf("%d",&x);
    while(x!=0)
    {
        y=(y*10)+(x%10);
        x/=10;
    }
    printf("The Reversed Number is : %d",y);
}
