// File: intcon.c | System: Dell | Time: 06:59 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:59 AM.59 
//


#include <stdio.h>

int main(void) {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int c[13] = {13,12,11,1,2,3,4,5,6,7,8,9,10};
    int res[6];
    intcon(a,c,res);
    for(int i=0;i<6;i++) {
        printf("%d ",res[i]);
    }
    return 0;
}
void intcon(int* a,int* b,int* c) {
    for(int i=0;i<3;i++) {
        *c = a[i];
        c++;
    }
    for(int i=0;i<3;i++) {
        *c = b[i];
        c++;
    }
}
