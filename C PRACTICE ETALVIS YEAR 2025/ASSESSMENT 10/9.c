// File: 9.c | System: Dell | Time: 05:43 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0505:43 AM.43 
//


#include <stdio.h>

int main(void) {
    char num[50] = "00000000000000465091827364509182736450918273645091";
    int i = 0;
    int start = 0;
    while (num[start] == '0'){
        start++;
    }
    int end = 50 - start;
    for (i = 0; i < end; i++) {
        num[i] = num[i + start];
    }
    // i = 0;
    // for (i = end; i < 50; i++) {
    //     num[i] = '0';
    // }
    num[50] = '\0';
    printf("The string is : %s", num);
    return 0;
}
