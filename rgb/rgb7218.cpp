#include <stdio.h>
#include <math.h>

int main() {
    long long a, n, sum = 0;
    scanf("%lld %lld", &a, &n);

    for (int i = 0; i <= n; i++) sum += pow(a, i);

    printf("%lld\n", sum);
}
