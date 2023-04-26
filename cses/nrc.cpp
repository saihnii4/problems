#include <iostream>
#include <set>
#include <algorithm>
#include <tuple>
#include <utility>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    bool is_contained[n];
    bool contains[n];

    tuple<long long, long long, int> arr[n];

    for (int i = 0; i < n; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        arr[i] = tuple<long long, long long, int>(a, b, i);
    }

    sort(arr, arr + n);

    set< tuple<long long, long long, int> > sub;

    for (int i = 0; i < n; i++) {
        auto it = sub.lower_bound(tuple<long long, long long, int>(0, get<1>(arr[i]), 0));
        is_contained[get<2>(arr[i])] = false;
        contains[get<2>(arr[i])] = false;

        if (it != sub.end()) {
            is_contained[get<2>(arr[i])] = true;

            while (it != sub.end()) {
                contains[get<2>(*it)] = true;
                ++it;
            }

        }

        sub.insert(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << contains[n] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << is_contained[n] << " ";
    }
    cout << endl;
}
