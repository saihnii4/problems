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

        long long f = 0;

        for (long long b = 9; q > b; b += n * 9 * pow(10, n - 1)) {
            ++n;
            f = b;
        }

        c -= f;

        long long place = (c - 1) % n + 1;
        long long group = (long long)((c-1) / n);

        group += pow(10, n - 1);
        place = n - place + 1;

        long long digit = (long long)((group % (long long)pow(10, place)) / pow(10, place - 1));
        printf("%lld\n", digit);
    }
}
