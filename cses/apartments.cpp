#include <stdio.h>
#include <algorithm>

int N = 2e5;

using namespace std;

int main() {
    int n , M, ppl[N], apt[N];
    long long K;
    scanf("%d %d %lld", &n, &M, &K);

    for (int i = 0; i < N; i++) scanf("%d", &ppl[i]);
    for (int i = 0; i < M; i++) scanf("%d", &apt[i]);

    sort(ppl, ppl+n);
    sort(apt, apt+n);

    int i = 0, j = 0, count = 0;

    while (i < n && j < M) {
        if (abs(ppl[i] - apt[j]) <= K) {
            ++i;
            ++j;
            ++count;
        } else {
            if (ppl[i] - apt[j] > K) {
                ++j;
            } else {
                ++i;
            }
        }
    }

    printf("%d\n", count);

}
