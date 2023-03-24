#include <stdio.h>

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long min(long long a, long long b) {
    return b > a ? a : b;
}

int main() {
    int T;
    long long a, b;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%lld %lld", &a, &b);

        if ((a + b) % 3 != 0) {
            printf("NO\n");
            continue;
        }

        if (a != b && max(a, b) - 2 * min(a, b) != 0) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
    }

    return 0;
}
