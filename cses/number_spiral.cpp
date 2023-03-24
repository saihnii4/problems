#include <stdio.h>

long long max(long long a, long long b) { return a > b ? a : b; }

int main() {
    long long T;
    scanf("%lld", &T);

    for (long long i = 0; i < T; i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        long long sq = max(x, y);
        long long c = sq*sq-sq+1;

        if (x == y)  printf("%lld\n", c);
        else if (x > y) printf("%lld\n", c - (x - y));
        else if (x < y) printf("%lld\n", c + (y - x));
    }
}
