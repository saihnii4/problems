#include <stdio.h>
#include <math.h>

int main() {
    int n, m;
    long long rounds = 1;
    scanf("%d %d", &n, &m);

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

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        arr[a] ^= arr[b];
        arr[b] ^= arr[a];
        arr[a] ^= arr[b];

        /* for (int i = 1; i <= n; i++) { */
        /*     printf("%d\n", arr[i]); */
        /* } */
        /* printf("\n"); */
        /*  */
        /* printf("%d %d %d %d\n", arr[a], arr[b], a, b); */

        if (b > a) {
            a ^= b;
            b ^= a;
            a ^= b;
        }

        if (abs(a - b) == 1) {
            if (arr[b] < arr[a]) --rounds;
            if (arr[a] < arr[b]) ++rounds;
        } else {
            if (a > 1 && arr[b] >= arr[a - 1] && arr[a] < arr[a - 1]) ++rounds;
            if (abs(a - b) != 1 && a != n && arr[b] <= arr[a + 1] && arr[a] > arr[a + 1]) ++rounds;
            if (b > 1 && arr[a] >= arr[b - 1] && arr[b] < arr[b - 1]) ++rounds;
            if (abs(a - b) != 1 && b != n && arr[a] <= arr[b + 1] && arr[b] > arr[b + 1]) ++rounds;

            if (a > 1 && arr[b] < arr[a - 1] && arr[a] > arr[a - 1]) --rounds;
            if (abs(a - b) != 1 && a != n && arr[b] > arr[a + 1] && arr[a] < arr[a + 1]) --rounds;
            if (b > 1 && arr[a] < arr[b - 1] && arr[b] > arr[b - 1]) --rounds;
            if (abs(a - b) != 1 && b != n && arr[a] > arr[b + 1] && arr[b] < arr[b + 1]) --rounds;
        }

        printf(">%lld\n", rounds);
    }
}
