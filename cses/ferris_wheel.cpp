#include <stdio.h>
#include <functional>
#include <set>

using namespace std;

int n;
long long x;
set<long long, greater<int> > nums;

int main() {
    scanf("%d %lld", &n, &x);

    for (int i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);
        nums.insert(x);
    }
}
