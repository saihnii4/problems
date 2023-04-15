// todo

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

typedef tuple<long long, long long> customer;
multiset<customer> schedule;
long long room = 1;
int n;

bool cmp(customer x, customer y) {
    return get<1>(x) < get<0>(y);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        long long start, end;
        scanf("%lld %lld", &start, &end);
        schedule.insert(customer(start, end));
    }

    auto a = schedule.lower_bound(*(schedule.begin()));

    while (a != schedule.end()) {
        auto next = a;
        ++next;
        if (next == schedule.end()) break;
        if (!cmp(*a, *next)){
            schedule.erase(*a);
            ++a;
            continue;
        }

        ++a;
    }

    printf("%lld\n", schedule.size());

    ++room;

    return 0;
}
