#include <stdio.h>
#include <math.h>

// converting n to base 3 with recursive approach cause yes
long long construct(long long n, int i) {
    if (n <= 0) return 0;
    int d = 1;
    if (n % 3 == 2) d = 3;
    else if (n % 3 == 0) d = 7;

    return (long long)(pow(10,i)*d) + construct((long long)((n-1) / 3), i + 1);
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", construct(n, 0));
}
