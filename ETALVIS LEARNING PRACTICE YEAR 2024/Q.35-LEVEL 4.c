/*Question: Get 2 numbers from user and find the LCM of them.
Example: Input 20,30 Output:60*/

#include<stdio.h>
int main()
{
    int a,b;
    int prod,i,lcm;
    printf("Enter two numbers :");
    scanf("%d %d",&a,&b);
    prod=a*b;
    for(i=1;i<=prod;i++)
    {
        if(((i%a)==0)&&((i%b)==0))
        {
            lcm=i;
            break;
        }
    }
    printf("The LCM of %d and %d is : %d",a,b,lcm);
}
