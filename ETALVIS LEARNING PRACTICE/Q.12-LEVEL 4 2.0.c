/*Question: Get a number from the user and print the reverse of it.
Example: User Enters “123456”
Answer - 654321*/

#include<stdio.h>
#include<math.h>.
int count(int num);
int x;
int countn=0;
int rev;
int main ()
{

printf("Enter the number :");
scanf("%d",&x);
countn=count(x);
int temp;
temp=countn-1;
int ones=x%10;
while(temp!=0)
{

    rev+=(x%10)*(pow(10,temp));
    printf("%d\n",rev);
    x/=10;
    printf("%d\n",x);
    temp-=1;
}
printf("The reversed number is : %d",rev);
}

int count(int num)
{
    while (num!=0)
    {
        countn++;
        num/=10;


    }
    return countn;
}
