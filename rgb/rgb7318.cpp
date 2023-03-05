#include <stdio.h>

int main() {
    long long int N, B = 10;
    scanf("%lld", &N);
    long long int A = N*10 + 1;

    while (N > 0) {
        N /= 10;
        B *= 10;
    }

    printf("%lld\n", (B + A)*(B + A));
    return 0;
}
