#include <set>
#include <tuple>
#include <queue>
#include <stdio.h>

using namespace std;

typedef tuple<long long, long long, int> customer;
typedef tuple<long long, int> slot;

priority_queue< int, greater<int> > available_rooms;
multiset<customer> arr;
int n;

int main() {
    scanf("%d\n", &n);
    int rooms[n];

    for (int i = 0; i < n; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        arr.insert(customer(a, b, i));
    }

    for (customer c : arr) {

    }
}
