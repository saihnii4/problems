// TODO:

#include <stdio.h>
#include <iterator>
#include <algorithm>

int n, m;

int main() {
    scanf("%d %d", &n, &m);

    int arr[n+1];

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arr[t] = i;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", arr[i]);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        long long rounds = 1;

        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;

        for (int i = 1; i <= n; i++) {
            printf("%d\n", arr[i]);
            if (i == n) break;
            if (arr[i] > arr[i + 1]) ++rounds;
        }

        printf("\n%lld\n\n", rounds);
    }
}
