#include <stdio.h>

int main() {
    int n;
    long long rounds = 1;
    scanf("%d", &n);

    int arr[n+1];

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arr[t] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (i == n) break;
        if (arr[i] > arr[i + 1]) ++rounds;
    }

    printf("%lld\n", rounds);
}
