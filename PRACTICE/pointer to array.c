#include <stdio.h>
#include <string.h>
int main(void) {
    int a = 10;
    int *p = a;
    printf("%x\n",p+1);
}