#include <stdio.h>
#include <math.h>
#include <set>

using namespace std;

int ct, n;
set<long long> b;
long long x, sum;

int main() {
    scanf("%d %lld", &n, &x);

    b.insert(0);

    for (int i = 1; i <= n; i++) {
        long long t;
        scanf("%lld", &t);
        sum += t;
        b.insert(sum);
    }

    bool once = true;

    for (long long sum : b) {
        if (b.find(x + sum) == b.end()) {
            continue;
        }

        ++ct;
    }

    printf("%d\n", ct);
}
