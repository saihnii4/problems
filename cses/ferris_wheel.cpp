#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    long long x;
    scanf("%lld %lld", &n, &x);
    vector<long long> child;

    for (int i = 0; i < n; i++) {
        long long T;
        scanf("%lld", &T);
        child.push_back(T);
    }

    sort(child.begin(), child.end());

    long long count = 0;

    for (long long i = child.size() - 1; i >= 0; i--) {
        /* for (long long i : child) { */
        /*     printf("%lld\n", i); */
        /* } */
        /* printf("\n"); */
        long long gondola = x;
        long long c = i;
        if (child[i] == -1) continue;
        gondola = x - child[i];
        /* printf("%lld\n%lld\n%lld\n\n", gondola, child[i], child[c]); */
        child[i] = -1;
    
        // since child is already sorted, binary search in O(log n) would make it faster maybe ???
        for (long long j = c; j >= 0 && (gondola != 0); j--) if (child[j] != child[c] && child[j] <= gondola) {
            if (gondola - child[j] < 0) continue;
            gondola -= child[j];
            /* printf("%lld k%d -> %d\n", gondola, i, j); */
            child[j] = -1;
            break;
        }

        ++count;
    }

    printf("%lld\n", count);
}
