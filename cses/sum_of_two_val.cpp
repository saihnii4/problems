#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

vector<long long> poss;

int main() {
    long long n, x;
    scanf("%lld %lld", &n, &x);

    for (long long i = 0; i < n; i++) {
        long long m;
        scanf("%lld", &m);
        poss.push_back(m);
    }

    sort(poss.begin(), poss.end());

    long long i = 1;
    for (long long num : poss) {
        auto res = find(poss.begin(), poss.end(), x - num);
        if (res != poss.end() && i != distance(poss.begin(), res) + 1) {
            printf("%lld %ld\n", i, distance(poss.begin(), res) + 1);
            return 0;
        } 
        ++i;
    }

    printf("IMPOSSIBLE\n");
}
