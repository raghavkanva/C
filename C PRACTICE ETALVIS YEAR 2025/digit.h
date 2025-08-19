#ifndef DIGIT_H
#define DIGIT_H

#include <stdio.h>
#include<math.h>
int countDigit(int x) {
    int count = 0;
    count = log10(x)+1;
    return count;
}
int digitExtract(int x,int p) {
    int lowerPower = (int)pow(10, p - 1);
    int upperPower = (int)pow(10, p);
    return (x % upperPower) / lowerPower;
}

#endif
