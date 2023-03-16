#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n*(n+1) % 4 != 0) printf("NO\n");
    else {
        long long d = (long long)(n*(n+1)/4);
        long long c = n;
        long long j = 1;

        long long a[n];
        long long b[n];
        for (int i = 0; i < n; i++) b[i] = i + 1;

        a[0] = n;
        b[n - 1] = 0;

        for (long long i = n - 1; c != d; i--) {
            if (d - c > i) {
                c += i;
                a[n - i] = i;
                b[i - 1] = 0;
            } else {
                a[n - i] = d - c;
                b[d - c - 1] = 0;
                c += d - c;
            }
            ++j;
        }

        printf("YES\n%lld\n", j);
        for (int i = 0; i < j; i++) {
            printf("%lld", a[i]);
            if (i != j) printf(" ");
        }
        printf("\n");

        printf("%lld\n", n - j);
        for (int i = 0; i < n; i++) {
            if (b[i] != 0) {
                printf("%lld", b[i]);
                if (i != n - 1) printf(" ");
            }
        }
        printf("\n");
    }
}
