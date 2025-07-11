//Array Pointers Practice

#include<stdio.h>
void main()
{
    int num[]={2,34,56,67,78,89,90};
    printf("The address of this array is: %u and the addrees of the second element is : %u\n",&num,&num[1]);
    //We can note that the differnce between the first and second element address id 4 bytes
    printf("The value of %dth element by using derefence pointer is %d\n",0,*(num));
    //now *(num) is same as *(num + 0) and num[0]
    printf("The value of %dth element by using normal method is %d\n",0,num[0]);
    //Thus internally num[i] is converted to *(num + i)
    printf("The value of %dth element by using i[num] method is %d\n",0,0[num]);//0[num] is valid but it is not a conventional way to use
    // The reason it is vlaid it *(num + i) and *(i + num) is same as a+b = b+a



}
