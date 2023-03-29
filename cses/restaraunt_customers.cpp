#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

long long p[400000];

long long abscmp(long long x, long long y) {
    return abs(x) < abs(y);
}

int main() {
    memset(p, 0, 400000*sizeof(long long));

    vector<int> v;

    long long t;
    scanf("%lld", &t);

    for (long long i = 0; i < t; i++) { 
        long long x, y;
        scanf("%lld %lld", &x, &y);

        v.push_back(x);
        v.push_back(-y);
    }

    sort(v.begin(), v.end(), abscmp);

    long long max = 0;
    long long bruh = 0;

    for (long long i : v) {
        if (i < 0) --bruh;
        else ++bruh;

        if (bruh > max) max = bruh;
    }

    printf("%lld\n", max);
}
