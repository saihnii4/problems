#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long sum = 0;

    for (int i = 0; i < n - 1; i++) {
        int t;
        scanf("%d", &t);
        sum += t;
    }

    printf("%lld\n", (long long)(n*(n+1)/2) - sum);
}
