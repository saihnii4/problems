#include <stdio.h>

long long sum = 0;

long long fsum(long long n) {
    if (n <= 1) return 1;
    int a = fsum(n - 1);
    sum += a;
    return n*a;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", fsum(n) + sum);
}
