// File: 7.c | System: Dell | Time: 05:25 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0505:25 AM.25 
//


#include <stdio.h>

int main(void) {
    char string[] = "Raghav Kanva";
    int i = 0, count = 0;;
    while (string[i] != '\0') {
        count++;
        i++;
    }
    printf("The length of the string is : %d", count);
    return 0;
}
