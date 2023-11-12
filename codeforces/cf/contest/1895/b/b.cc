#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int a, t;
int main() {
  cin >> t;
  while (t--) {
    cin >> a;
    vector<ll> v(2 * a, 0);
    for (int i = 0; i < 2 * a; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 1; i < a; i++) {
      ans += abs(v[i] - v[i - 1]);
    }
    for (int i = a + 1; i < 2 * a; i++) {
      ans += abs(v[i] - v[i - 1]);
    }
    cout << ans << endl;
    for (int i = 0; i < a; i++) {
      cout << v[i] << ' ' << v[2 * a - i - 1] << endl;
    }
  }
}
