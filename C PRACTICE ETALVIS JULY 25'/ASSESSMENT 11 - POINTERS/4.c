// File: 4.c | System: Dell | Time: 06:26 AM | Date: 23-07-2025 | Year: 2025 | ID: 232025.0606:26 AM.26 
//


#include <stdio.h>

#include "../sum.h"

sum7(int* ptr) {
    for (int i = 10; i < 100; i++) {
        if ((i%2 != 0) && (sum(i) == 7)) {
            *ptr = i;
            *ptr++;
        }


    }
}

int main() {
    int arr[50];
    sum7(arr);
    int i = 0;
    while (arr[i] != '\0') printf("%d\n", arr[i++]);
    return 0;
}