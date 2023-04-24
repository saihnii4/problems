#include <set>
#include <algorithm>
#include <tuple>
#include <queue>
#include <stdio.h>

using namespace std;

typedef tuple<long long, long long, int> customer;
typedef tuple<long long, int> occupation;
typedef tuple<long long, int> slot;

priority_queue< int, vector<int>, greater<int> > available_rooms;
multiset<customer> arr;
queue<occupation> garbage;
set<occupation> day;
int n;

int main() {
    scanf("%d\n", &n);
    int room;
    int rooms[n];

    for (int i = 0; i < n; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        available_rooms.push(i + 1);
        arr.insert(customer(a, b, i));
    }

    for (customer c : arr) {
        auto it = day.lower_bound(occupation(get<1>(c), 0));

        if (it != day.end()) --it;
        while (it != day.end()) {
            garbage.push(*it);
            available_rooms.push(get<1>(*it));
            ++it;
        }

        int nearest_room = available_rooms.top();

        occupation slot = make_tuple(get<1>(c), nearest_room);
        room = max(nearest_room, room);

        day.insert(slot);
        rooms[get<2>(c)] = nearest_room;
        available_rooms.pop();

        while (!garbage.empty()) {
            day.erase(garbage.front());
            garbage.pop();
        }
    }

    printf("%d\n", room);

    for (int i = 0; i < n; i++) {
        printf("%d ", rooms[i]);
    }

    printf("\n");

    return 0;
}
