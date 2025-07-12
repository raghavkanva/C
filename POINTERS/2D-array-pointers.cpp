#include<stdio.h>
int main(){
    int arr[3][2]={{12,23},{34,56},{78,89}};
    //print the address of the array
    printf("The address of the array is : %u\n",&arr);
    //Now we will print the address of each individual array
    for(int i=0;i<3;i++){
        printf("The address of the %d array is : %u\n",i,&arr[i]);
    }
    //Here we can notice that the size of each individual array is 8 bytes , since there are two elements in each array

    //Now let us try on an array which has some uninitialised elements
    int arrunit[2][2]={{1},{3,4}};
    //print the address of the array
    printf("\nThe address of the array is : %u\n",&arrunit);
    //Print the value of second element in first array
    printf("The value of the uninitialised element is : %d\n",arrunit[0][1]);//For partially assigned array, the uninitialised elements are set to zero
    //Now we will print the address of each individual array
    for(int i=0;i<2;i++){
        printf("The address of the %d array is : %u\n",i,&arrunit[i]);
    }


    return 0;
}
