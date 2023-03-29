// slow
/*  */
/* #include <stdio.h> */
/* #include <set> */
/*  */
/* using namespace std; */
/*  */
/* int main() { */
/*     long long n, uniq = 0; */
/*     scanf("%lld", &n); */
/*     set<long long> s; */
/*  */
/*     for (long long i = 0; i < n; i++){ */
/*         long long t; */
/*         scanf("%lld", &t); */
/*         s.insert(t); */
/*     } */
/*  */
/*     printf("%lld\n", s.size()); */
/* } */

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);

    vector<long long> v;

    for (int i = 0; i < n; i++) {
        long long t;
        scanf("%lld", &t);

        v.push_back(t);
    }

    sort(v.begin(), v.end());

    long long tmp = v[0];
    long long ct = 1;

    for (long long i : v) {
        if (i != tmp) {
            ++ct;
            tmp = i;
        }
    }

    printf("%lld\n", ct);
    return 0;
}
