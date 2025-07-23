// File: 11.c | System: Dell | Time: 06:02 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:02 AM.02 
//


#include <stdio.h>

int main(void) {
    char num[50] = "00000000000000465091827364509182736450918273645091";
    int numArr[50];
    for (int i = 0; i < 50; i++) {
        numArr[i] = (int)num[i]-'0';
        printf("The integer array is %d\n",numArr[i]);
    }

    return 0;
}
