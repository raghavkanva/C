// File: 10.c | System: Dell | Time: 05:55 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0505:55 AM.55 
//


#include <stdio.h>

int main(void) {
    char num[50] = "34827593418237465091827364509182736450918273645091";
    char temp;
    for (int i = 0; i < 25; i++) {
        temp = num[i];
        num[i] = num[50-i-1];
        num[50-i-1] = temp;
    }
    num[50] = '\0';
    printf("The reversed string is : %s", num);
    return 0;
}
