#include <math.h>
#include <stdio.h>

#include "../digit.h"
//
// Created by Dell on 21-07-2025.
//
void main() {
    int x=364925;
    int count=0;
    // printf("Enter the number:");
    // scanf("%d",&x);
    int len = countDigit(x);
    for (int i = len; i > 1; i--) {
        int d1 = digitExtract(x, i);
        int d2 = digitExtract(x, i - 1);
        int numToCheck = d1 * 10 + d2;

        int root = (int)sqrt(numToCheck);
        if (root * root == numToCheck)
            count++;
    }

    printf("Count of perfect square digit pairs = %d\n", count);
}