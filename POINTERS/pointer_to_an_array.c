#include<stdio.h>
int main(){
    int arr[][2]={{1,2},{3,4}};
    int *p;//This is an Integer Pointer
    int(*q)[2];//This is a pointer to an aray

    //Actually p = arr[2] and p = &arr[2] are totally valid
    //Also p = &(arr) + i is also valid
    //But p = &(arr + 1) is invalid
    p = &(arr) + 0;
    q = arr;

    printf("\n   P            Q\n");
    printf("%u  %u\n",p,q);
    p++;
    q++;
    printf("%u  %u\n",p,q);
}