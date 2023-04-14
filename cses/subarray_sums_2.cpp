#include <stdio.h>
#include <map>
#include <tuple>
#include <math.h>
#include <set>

using namespace std;

int ct, n;
map<long long, int> freq;
multiset<long long> b;
long long x, sum;

int main() {
    scanf("%d %lld", &n, &x);

    for (int i = 1; i <= n; i++) {
        long long t;
        scanf("%lld", &t);
        sum += t;
        b.insert(sum);
    }

    for (long long sum : b) {
        if (b.find(x + sum) == b.end()) continue;
        if (freq.find(x + sum) == freq.end())
            freq[x + sum] = 0;
        ct += b.count(x + sum) - freq[x + sum];
        freq[x + sum]++;
    }

    printf("%d\n", ct);
}
