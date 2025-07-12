#include<stdio.h>
void main(){
    int arr[2][2]={{1,2},{3,4}};
    disp1(arr,2,2);
    disp2(arr,2,2);
    //disp3(arr,2,2);
}
disp1(int *p, int r, int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("The address is : %u and the value is : %d\n",p + i*c + j,*(p + i*c + j));
        }
    }
}

disp2(int (*q)[2], int r, int c){
    printf("Display 2 Function :\n");
    int i,j;
    int*p;
    for(int i = 0; i < r; i++){
        p = q + i;
        for(int j = 0; j < c; j++){
            printf("%d\n",*(p+j));
        }
    }
}