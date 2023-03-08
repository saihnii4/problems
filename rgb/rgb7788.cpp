#include <stdio.h>
#include <math.h>

int main() {
    int n, k, b = 0, c = 0;
    scanf("%d %d", &n, &k);

    int d[n];

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        d[i] = t;
        b |= (1 << t);
    }

    for (int i = 0; i < n; i++) {
        int temp = b ^ (1 << d[i]);
        if ((temp & (1 << abs(k - d[i]))) != 0) ++c;
    }

    printf("%d\n", c);

    return 0;
}
