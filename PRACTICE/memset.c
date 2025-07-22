// File: memset.c | System: Dell | Time: 04:18 PM | Date: 22-07-2025 | Year: 2025 | ID: 222025.1604:18 PM.18 
//


#include <stdio.h>
#include <string.h>

int main(void) {
    char mem[20];
    memset(mem,'1',19);
    mem[19]='\0';
    printf("String is %s",mem);
    return 0;
}
