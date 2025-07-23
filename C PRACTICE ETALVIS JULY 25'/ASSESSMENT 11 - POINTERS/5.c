// File: 5.c | System: Dell | Time: 06:35 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:35 AM.35 
//


#include <stdio.h>

int main(void) {
    int source[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dest[10];

    memcopy(source,dest,8);

    for (int i = 0; i < 8; i++) {
        printf("%d\n", dest[i]);
    }
    return 0;
}
void memcopy(int *source,int *dest,int n) {
    for (int i = 0; i < n; i++) {
        *(dest + i) = *(source + i);
    }
}
