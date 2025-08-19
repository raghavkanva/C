#include <stdio.h>

#include "../digit.h"
//
// Created by Dell on 21-07-2025.
//
int main() {
    long x;
    int count=0;
    printf("Enter the number:");
    scanf("%ld",&x);
    for(int i=1;i<=x;i++) {
        if (digitExtract(x,i)%2==1) count++;
    }
    printf("Odd-Digit Count : %d",count);
}
