#include <stdio.h>
#include <math.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long zeroes = 0;

    for (int i = 5; n / i >= 1; i *= 5) {
        zeroes += floor(n / i);
    }

    printf("%lld\n", zeroes);
}
