// todo: fix janky
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
using ll = long long;
// template <typename T>
struct SparseTable {
  int n, k;
  vector<ll> arr;
  vector<vector<ll>> dp;
  ll merge(ll l, ll r) { return min(l, r); }
  SparseTable(vector<ll> arr)
      : n(arr.size()), arr(arr), k(floor(log2(n))), dp(n, vector<ll>(k, 0)) {
    for (int i = 0; i < n; i++) {
      dp[i][0] = arr[i];
    }
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j + (1 << i) <= n; j++) {
        dp[j][i] = merge(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
      }
    }
  }

  ll query(ll l, ll r) {
    ll ans = 0;
    while (l < r) {
      int k = floor(log2(r - l + 1));
      ans += dp[l][k - 1];
      l += (1 << (k - 1));
    }
    return ans;
  }
};
int main() {
  freopen("sample", "r", stdin);
  int n, q;
  cin >> n >> q;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  auto st = SparseTable(arr);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l - 1, r) << endl;
  }
  return 0;
}
