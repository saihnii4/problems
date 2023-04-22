#include <stdio.h>

#define INF 10e9 + 1

int n, q;

int main() {
    scanf("%d %d", &n, &q);

    long long arr[n];
    long long prefix_arr[n + 1];
    prefix_arr[0] = INF;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] < prefix_arr[i - 1]) prefix_arr[i] = arr[i];
        else prefix_arr[i] = prefix_arr[i-1];
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
    }
}
