#ifndef SUM_H
#define SUM_H

#include <stdio.h>

static int sum(int n) {
    int sum = 0;
    while (n!=0) {
        sum += n%10;
        n = n/10;
    }
    return sum;
}

#endif
