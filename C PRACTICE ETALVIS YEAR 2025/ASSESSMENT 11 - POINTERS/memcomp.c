// File: memcomp.c | System: Dell | Time: 06:44 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:44 AM.44 
//


#include <stdio.h>

void memcomp(int * arr, int * arr1, int i) {
    for (int j = 0; j < i; j++) {
        if (*(arr + j) != *(arr1 + j)) printf("Not Success");
    }

}

int main(void) {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {1,2,9,4,5,5,7,8,9,10};
    memcomp(a,b,5);
    return 0;
}
