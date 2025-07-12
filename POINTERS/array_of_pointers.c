#include<stdio.h>
int main(){
    int *arr[4];
    int a=10,b=20,c=30,d=40;
    arr[0]=&a;
    arr[1]=&b;
    arr[2]=&c;
    arr[3]=&d;
    printf("\n Address of Array arr :");
    for(int i=0;i<4;i++){
        printf("\n%u",arr[i]);
    }
    printf("\n");

    //Array of pointers to hold addresses of other array
    int aj[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int *p;
    for(int i=0;i<12;i++){
        p=&aj[i];
        printf("\n%u %u %u",p,*p,*(&p));
    }

}