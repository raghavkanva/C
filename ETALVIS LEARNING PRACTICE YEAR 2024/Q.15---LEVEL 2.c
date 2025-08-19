#include<stdio.h>
#include<math.h>
int num,count,fnum,lnum,new1,new2,num20,temp1;
int main()
{
    printf("Enter the number : ");
    scanf("%d",&num);
    temp1=num;
    while((temp1/10)!=0)
    {
        count+=1;
        temp1/=10;
    }
    fnum=temp1%10;
    if((num%2)!=0)
    {
        int pow2=pow(10,count);
        new1=(fnum-1)*pow2;
        new2=num%pow2;
        num20=new1+new2;
        printf("The number is : %d",num20);
    }
    else
    {
        printf("The number is : %d",num);
    }
}
