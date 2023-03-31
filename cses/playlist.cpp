#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, mx;

int main() {
    scanf("%d", &n);

    vector<long long> playlist;

    for (int i = 0; i < n; i++) {
        long long t;
        scanf("%lld", &t);
        playlist.push_back(t);
    }

    vector<long long> sub;

    for (int i = 0; i < n; i++) {
        if (sub.size() > mx) mx = sub.size();

        if (find(sub.begin(), sub.end(), playlist[i]) != sub.end()) {
            sub = vector<long long>{};
        }

        sub.push_back(playlist[i]);
    }

    if (sub.size() > mx) mx = sub.size();
    printf("%d\n", mx);
}
