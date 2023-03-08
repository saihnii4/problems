#include <stdio.h>

int main() {
    long long n, k = 1;
    scanf("%lld", &n);

    while (n > 0) {
        k *= n;
        n -= 2;
    }

    printf("%lld\n", k);
}
