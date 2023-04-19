#include <stdio.h>
#include <utility>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<long long, int> freq;
int n, ct;
long long sum, k;
unordered_set<long long> primitive_lkp;
unordered_multiset<long long> main_lkp;

int main() {
    scanf("%d %lld", &n, &k);
    long long arr[n];

    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        primitive_lkp.insert(sum);
    }

    for (long long val : primitive_lkp) {
        if (val < k)
            val = k - val;
        else val %= k;

        printf("%lld\n", val);
        main_lkp.insert(val);
    }

    printf("\n");

    int i = 0;

    for (long long val : main_lkp) {
        printf("%lld\n", val);
        if (!freq[val]) freq[val] = 0;
        ct += main_lkp.count(k - val) - freq[val];
        freq[val]++;
    }

    return 0;
}
