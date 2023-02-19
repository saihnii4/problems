#include <stdio.h>

int a, b;

int next_prime(int* p, int sieve) {
    int s = (sieve >> *p) << *p;
    int loc = __builtin_popcount((s & -s) - 1);
    *p = loc + 1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &a, &b);
        int sieve = (1 << b) - 2;

        for (int p = 2; p <= b; next_prime(&p, sieve)) {
            printf("%d\n", p);
            for (int j = 2*p; j <= b; j+=p) {
                if (sieve & (1 << (j-1))) sieve ^= (1 << j) >> 1;
            }
        }
        printf("\n");
    }

    return 0;
}
