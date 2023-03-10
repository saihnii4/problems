#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        long long a = 1;
        for (int j = i; j <= 2*i; j++) {
            a *= j;
        }
        sum += a;
    }

    printf("%lld\n", sum);

    return 0;
}
