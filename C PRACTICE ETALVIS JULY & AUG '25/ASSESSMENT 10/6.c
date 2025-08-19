// File: 6.c | System: Dell | Time: 04:46 PM | Date: 22-07-2025 | Year: 2025 | ID: 222025.1604:46 PM.46 
//


#include <stdio.h>

#include "../digit.h"

int main(void) {
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    int len = countDigit(a);
    for(int i=0;i<len;i++) {
        printf("%c\n",a%10+'0');
        a=a/10;
    }
    return 0;
}
