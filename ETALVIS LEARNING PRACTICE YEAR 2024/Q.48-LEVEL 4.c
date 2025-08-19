#include<stdio.h>
int main()
{
    int arr[]={6,12,3,15,7};
    int res[5];
    int carry=0;
    int i=0;
    printf("Array :              ");
    for(i=4;i>=0;i--)
    {
        res[i]=((arr[i]%10)+carry);
        carry=(arr[i]/10);
        printf("%d   ",arr[i]);

    }
    printf("\nResultant array :    ");
    for(i=0;i<5;i++)
    {
        printf("%d\    ",res[i]);
    }

}
