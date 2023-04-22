#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n;
long long x, max_t, d = -1;

vector<long long> s;

bool valid(long long t) {
    auto ptr = s.begin();
    long long items = 0;
    for (int i = 0; i < n; i++) {
        items += t/(*ptr);
        ++ptr;
    }

    return items >= x;
}

int main() {
    scanf("%d %lld", &n, &x);

    for (int i = 0; i < n; i++) {
        long long t;
        scanf("%lld", &t);
        s.push_back(t);
    }

    sort(s.begin(), s.end());

    max_t = x*(*s.begin());

    for (long long b = max_t + 1; b >= 1; b /= 2) {
        while (!valid(d + b)) d += b;
    }
    
    printf("%lld\n", d + 1);

    return 0;
}
