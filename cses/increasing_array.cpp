#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    long long moves = 0;

    long long b[n];
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    for (long long i = 1; i < n; i++) {
        if (b[i] > b[i-1]) continue;
        moves += b[i-1]-b[i];
        b[i] = b[i-1];
    }

    printf("%lld\n", moves);
}
