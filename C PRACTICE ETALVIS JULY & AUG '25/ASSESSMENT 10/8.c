// File: 8.c | System: Dell | Time: 05:28 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0505:28 AM.28 
//


#include <stdio.h>

int main(void) {
    char num[50] = "34827593418237465091827364509182736450918273645091";
    for (int i = 0; i < 50; i++) {
        int ascii = num[i];
        if (ascii < 48 || ascii > 57) {
            printf("It is not a valid number !");
            return 1;
        }

    }
    printf("It is a valid number !");
    return 0;
}
