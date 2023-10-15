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
int n,t;
ll ans;
char arr[1000][1000];
ll count(ll x, ll y) {
  ll self = arr[y][x];
  ll r = arr[y][n-x-1];
  ll br = arr[n-y-1][n-x-1];
  ll b = arr[n-y-1][x];
  ll m1 = max(self, r);
  ll m2 = max(br, b);
  ll mx = max(m1, m2);
  return 4*mx - (self+r+br+b);
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n;
    for (int i=0;i<n;i++) {
      string str;
      cin >> str;
      for (int j=0;j<n;j++) {
        arr[i][j] = str.c_str()[j];
      }
    }
    for (int i=0;i<n/2;i++) {
      for (int j=0;j<n/2;j++) {
        ans += count(j,i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
