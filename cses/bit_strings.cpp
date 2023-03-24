#include <stdio.h>
#include <math.h>

int main() {
    long long n;

    long long MOD = pow(10, 9) + 7;
    scanf("%lld", &n);
    long long r = 1;

    if ((n & 1) == 0) {
        for (long long i = 0; i < ((long long)n/2); i++) {
            r = (r * 4) % MOD;
        }
    } else {
        for (long long i = 0; i < n; i++) {
            r = (r * 2) % MOD;
        }
    }

    printf("%lld\n", r);
    
}
