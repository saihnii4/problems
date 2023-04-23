#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<long long, int> sums;
int n;
long long k, sum, ct;

int main() {
    scanf("%d %lld", &n, &k);
    vector<long long> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sums[0] = 1;

    for (long long x : arr) {
        sum += x;

        ct += sums[sum - k];
        ++sums[sum];
    }

    printf("%lld\n", ct);

    return 0;
}
