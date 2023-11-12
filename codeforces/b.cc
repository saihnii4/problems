#include <iostream>
#include <set>
using namespace std;
using ll = long long;
int t, n, q;
set<ll> mod;
void solve() {
    cin >> n >> q;
    for (int i=0;i<n;i++) {

    }
    for (int i=0;i<q;i++) {
        int t;
        cin >> t;
        mod[i].insert(1<<t);
    }
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}
