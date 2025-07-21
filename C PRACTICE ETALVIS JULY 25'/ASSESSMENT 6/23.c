#include <math.h>
#include <stdio.h>

#include "../digit.h"
//
// Created by Dell on 21-07-2025.
//
void main() {
    int x;
    int count=0;
    printf("Enter the number:");
    scanf("%d",&x);
    int len = countDigit(x);
    for (int i = 1; i <= len; i++) {
        int root = (int)sqrt(digitExtract(x,i));
        if (root*root == digitExtract(x,i)) count++;
    }
    printf("count=%d",count);
}