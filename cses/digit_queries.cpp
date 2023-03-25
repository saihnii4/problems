#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        long long q;
        scanf("%lld", &q);

        long long n = 1;
        long long c = q;

        long long f;

        for (long long b = 9; q > b; b += n * 9 * pow(10, n - 1)) {
            ++n;
            f = b;
        }

        c -= f;

        long long place = c % n;

        long long group = (long long)((c - 1) / n);

        printf("%lld\n", c);
        printf("%lld\n", n);
        printf("%lld\n", group);
        printf("%lld\n", place);
    }
}
