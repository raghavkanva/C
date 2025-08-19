// File: 2.c | System: Dell | Time: 04:27 PM | Date: 22-07-2025 | Year: 2025 | ID: 222025.1604:27 PM.27 
//


#include <stdio.h>

int main(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    //option 1
    printf("%d",num+'0');
    //option 2
    printf("%d",(char)num);
    return 0;
}
