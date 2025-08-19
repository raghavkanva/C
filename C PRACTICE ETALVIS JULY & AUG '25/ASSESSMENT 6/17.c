//
// Created by Dell on 21-07-2025.
//

#include <stdio.h>

#include "../isPrime.h"
#include "../sum.h"

int main() {
    int x;
    printf("Enter number:");
    scanf("%d",&x);
    if (isPrime(x)&&(sum(x)==14)) printf("Yes");
}
