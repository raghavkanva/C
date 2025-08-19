// File: 6.c | System: Dell | Time: 06:39 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:39 AM.39 
//


#include <stdio.h>

int main(void) {
    char str1[10] = "1234567891";
    char str2[10];
    strcopy(str1,str2);
    str2[10] = '\0';
    printf("%s",str2);
    return 0;
}
void strcopy(char *source, char *dest) {
    while (*source != '\0') *(dest++) = *(source++);
}
