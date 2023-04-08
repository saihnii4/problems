// TODO: get a new brain

#include <stdio.h>
#include <math.h>

int main() {
    int n, m;
    long long rounds = 1;
    scanf("%d %d", &n, &m);

    int arr[n+1];
    int sec_arr[n];

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        sec_arr[i] = t;
        arr[t] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (i == n) break;
        if (arr[i] > arr[i + 1]) ++rounds;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        sec_arr[a] ^= sec_arr[b];
        sec_arr[b] ^= sec_arr[a];
        sec_arr[a] ^= sec_arr[b];

        printf(">%lld\n", rounds);
    }
}
