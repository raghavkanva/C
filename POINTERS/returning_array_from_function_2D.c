#include<stdio.h>
#define ROW 3
#define COL 4
void main(){
    int i,j;

    //To return base address to a pointer to an integer
    int *a;
    int *fun1();
    a = fun1();
}

int *fun1(){
    static int a[ROW][COL] ={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int i,j;
    printf("\nArray a[][] in fun1():\n");
    for(i=0;i<ROW;i++){
       for(j=0;j<COL;j++){
           printf("%d\t",a[i][j]);
       }
       printf("\n");
    }
    return (int *)a;
}