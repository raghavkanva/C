#include<stdio.h>
void main(){
    int arr[2][3][4] = {
                           {
                               {1,2,3,4},
                               {5,6,7,8},
                               {9,10,11,12}
                           },
                           {
                                {13,14,15,16},
                                {17,18,19,20},
                                {21,22,23,24}
                           }
    };
    printf("The address of arr is : %u and this type of synta also gives the same : %u",&arr,arr);
    //Dereferncing the address of arr, gives the 0th element of the 3D Array i.e., 1st 2D Array
    printf("\n%u",*arr);
    //Further dereferencing gives the 0th element of 2D Array i.e., 1st 1D array
    printf("\n%u",**arr);
    //Finally it gives the 0th element of 1st 1D Array in 1st 2D Array
    printf("\n%u",***arr);


    printf("\nThe address of the 1st 2D Array is : %u",arr+1);
    printf("\nThe address of the 1st 1D Array is : %u",*arr+1);
    printf("\nThe address of the 1st 2D Array is : %u",**arr+1);
}

