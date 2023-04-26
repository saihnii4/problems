#include <set>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <stdio.h>

using namespace std;

typedef tuple<long long, long long, int> customer;
typedef tuple<long long, int> occupation;
typedef tuple<long long, int> slot;

priority_queue< int, vector<int>, greater<int> > q;
set<slot> occupied;
multiset<customer> arr;
int n, mx;

int main() {
    scanf("%d\n", &n);
    int room;
    int rooms[n];

    for (int i = 0; i < n; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        q.push(i);
        arr.insert(customer(a, b, i));
    }

    for (customer c : arr) {
        auto it = occupied.lower_bound(slot(get<0>(c) - 1, 0));

        if (it != occupied.end()) {
            q.push(get<1>(*it));
            while (it != occupied.begin()) {
                --it;
                q.push(get<1>(*it));
            }
            occupied.erase(*it);
        }

        occupied.insert(slot(get<1>(c), q.top()));
        rooms[get<2>(c)] = q.top();
        if (q.top() > mx) mx = q.top();
        q.pop();
    }

    printf("%d\n", mx + 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", rooms[i] + 1);
    }
    printf("\n");
}
