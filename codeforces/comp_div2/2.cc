#include <iostream>
#include <utility>
#include <algorithm>
using ll = long long;
using namespace std;
typedef pair<ll, ll> r;
ll t,n,p;
int main() {
    cin>>t;
    while (t--) {
        cin >> n >> p;
        r res[n];
        for (int i=0;i<n;i++) {
            cin >> res[i].second;
        }
        for (int i=0;i<n;i++) {
            cin >> res[i].first;
        }

        sort(res, res+n);
        ll x = 0;
        ll cost = 0;
        for(int i=0;i<n&&x<n;i++) {
            if (res[i].first > p) {
                cost += (n-x)*p;
                break;
            }
            cost += res[i].first*(res[i].second<=n-x?res[i].second : n - x);
            x += res[i].second;
        }
        cout << cost << endl;
    }
}