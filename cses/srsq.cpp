#include <stdio.h>

int n, q;

int main() {
    scanf("%d %d", &n, &q);
    long long arr[n];
    long long prefix_sum[n + 1];
    prefix_sum[0] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        prefix_sum[i+1] = prefix_sum[i] + arr[i];
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%lld\n", prefix_sum[y]-prefix_sum[x - 1]);
    }
}
