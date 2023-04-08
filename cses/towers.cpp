#include <stdio.h>
#include <set>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    set<long long> towers;

    for (int i = 0; i < n; i++) {
        long long k;
        scanf("%lld", &k);

        auto it = towers.upper_bound(k);

        if (it == towers.end()) {
            towers.insert(k);
            continue;
        }
    }
}
