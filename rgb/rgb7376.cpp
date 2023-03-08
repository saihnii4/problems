#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

// note: original problem went past 2**64 - 1

char* end = "";

// converting n to base 3 with recursive approach cause yes
std::string construct(long long n, int i) {
    if (n <= 0) return "";
    char d = '1';
    if (n % 3 == 2) d = '3';
    else if (n % 3 == 0) d = '7';

    return std::string() + construct((long long)((n-1) / 3), i + 1) + d;
}

int main() {
    long long n;
    scanf("%lld", &n);
    std::cout << construct(n, 0) << std::endl;
}
