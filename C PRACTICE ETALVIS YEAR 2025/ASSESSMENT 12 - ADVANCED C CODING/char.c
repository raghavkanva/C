
//


#include <stdint.h>
#include <stdio.h>

void check(char * str);

int main(void) {
    char c1[] = "Hello";
    check(&c1);
}
void check(char *str) {
    printf("%p %p %p",str++,str++,str);
}