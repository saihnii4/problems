#include <stdio.h>

long long max(long long a, long long b) { return a > b ? a : b; }

int main() {
    long long T;
    scanf("%lld", &T);

    for (long long i = 0; i < T; i++) {
        long long x, y;
        scanf("%lld %lld", &y, &x);

        long long sq = max(x, y);
        long long c = sq*sq-sq+1;

        if (x == y)  printf("%lld\n", c);
        else printf("%lld\n", ((sq & 1) == 0) ? c - (x - y) : c + (x - y));
    }
}
