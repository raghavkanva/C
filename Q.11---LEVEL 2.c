#include<stdio.h>
#include<math.h>
int main()
{
    int x;
    printf("Enter the number :");
    scanf("%d",&x);
    int z=1;
    int y=pow(10,z);
    loop:  if ((x%y)<x)
    {
        if((x%y)==x)
        {
            printf("No of digits are : %d",z);
        }
        else
        {
            z+=1;
            y=pow(10,z);
        }
        goto loop;
    }
}
