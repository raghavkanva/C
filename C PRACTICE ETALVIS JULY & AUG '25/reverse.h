#ifndef REVERSE_H
#define REVERSE_H
int reverse(int n) {
    int reversed = 0;
    while (n!=0) {
        reversed = reversed*10+n%10;
        n=n/10;
    }
    return reversed;
}
#endif //REVERSE_H
