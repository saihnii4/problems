// TODO:

#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef pair<long long, long long> range;

bool cmp(range r1, range r2) {
    return r1 != r2 && (r1.first <= r2.first) && (r1.second >= r2.second);
}

int main() {
    int n;
    scanf("%d", &n);

    vector<range> arr;

    for (int i = 0; i < n; i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        arr.push_back(range(x, y));
    }

    bool contains[n];
    bool is_contained[n];

    for (int i = 0; i < arr.size(); i++) { 
        range rng = arr[i];
        auto upp = upper_bound(arr.begin(), arr.end(), rng, cmp);
        auto low = lower_bound(arr.begin(), arr.end(), rng, cmp);

        cout << rng.first << " " << rng.second << " " << (*low).first << " " << (*low).second << endl;

        contains[i] = upp != arr.end();
        is_contained[i] = low != arr.begin();
    }

    for (int i = 0; i < n; i++) {
        printf("%d", contains[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d", is_contained[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
