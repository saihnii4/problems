#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    for (long long i = 1; i <= n; i++) {
        long long result = (i*i*(i*i-1) >> 1) - 4*(i - 1)*(i - 2);
        printf("%lld\n", result);
    }
    return 0;
}
