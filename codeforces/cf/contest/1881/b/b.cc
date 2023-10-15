#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int k;
ll t, a, b, c;
ll min(ll a, ll b, ll c) {
  ll d = (a > b) ? b : a;
  ll e = (b > c) ? c : b;
  return (d > e) ? e : d;
}
ll max(ll a, ll b, ll c) {
  ll d = (a > b) ? a : b;
  ll e = (b > c) ? b : c;
  return (d > e) ? d : e;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    bool found = false;
    k = 0;
    cin >> a >> b >> c;
    if (a == b && b == c) {
      cout << "YES" << endl;
      continue;
    }
    ll m = min(a, b, c);
    ll M = max(a, b, c);
    ll d = a ^ b ^ c ^ m ^ M;
    if (d % m == 0 && M % m == 0 && (d/m)-1+(M/m)-1 <= 3) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
