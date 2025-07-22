// File: 5.c | System: Dell | Time: 04:37 PM | Date: 22-07-2025 | Year: 2025 | ID: 222025.1604:37 PM.37 
//


#include <stdio.h>
#include <string.h>

#include "../digit.h"

int main(void) {
    int s;
    printf("Enter a string: ");
    scanf("%d",&s);
    int len;
    len = countDigit(s);
    char str[len+1];
    str[len] = '\0';
    int i = len-1;
    while (s != 0) {
        str[i] = (s%10) + '0';
        s = s/10;
        i--;
    }
    printf("You entered: %s", str);
    return 0;
}
