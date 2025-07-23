// File: strcomp.c | System: Dell | Time: 06:49 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:49 AM.49 
//


#include <stdio.h>

int main(void) {
    char str1[11] = "Ten10Ten10";
    char str2[11] = "Ten10Ten10";
    strcomp(str1,str2);
    return 0;
}
void strcomp(char *str1, char *str2) {
    while (*str1 != '\0') {
        if (*str1 != *str2) {
            printf("Not equal ");
        }
        str1++;
        str2++;
    }
}
