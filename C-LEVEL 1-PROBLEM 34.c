#include<stdio.h>
int main()
{
    int x1,x2,y;
    printf("Enter the first Number : ");
    scanf("%d",&x1);
    printf("Enter the second Number : ");
    scanf("%d",&x2);
    int ones1, ones2, tens1,tens2,hundreds1,hundreds2;
    ones1=x1%10;
    ones2=x2%10;
    tens1=(x1%100)/10;
    tens2=(x2%100)/10;
    hundreds1=x1/100;
    hundreds2=x2/100;
    int diff;
    if(tens1>tens2)
    {
        if (ones1>hundreds1)
        {
            diff=ones1-hundreds1;
        }
        else
        {
            diff=hundreds1-ones1;
        }
    }
    if(tens1<tens2)
    {
        if (ones2>hundreds2)
        {
            diff=ones2-hundreds2;
        }
        else
        {
            diff=hundreds2-ones2;
        }
    }
    printf("%d",diff);

}
