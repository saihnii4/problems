#include <iostream>
#include <math.h>
#include <utility>
using namespace std;
using ll = long long;
pair<ll, ll> dp[100001][100];
int n, q;
void build() {
  int k = floor(log2(n));
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      dp[j][i] = make_pair(
          min(dp[j][i - 1].first, dp[j + (1 << (i - 1))][i - 1].first),
          max(dp[j][i - 1].second, dp[j + (1 << (i - 1))][i - 1].second));
    }
  }
}
pair<ll, ll> query(ll l, ll r) {
  pair<ll, ll> ans = {1e9, -1e9};
  while (l < r) {
    int k = floor(log2(r - l + 1));
    ans = {min(ans.first, dp[l][k - 1].first),
           max(ans.second, dp[l][k - 1].second)};
    l += (1 << (k - 1));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /* freopen("sample", "r", stdin); */
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    dp[i][0] = {t, t};
  }
  build();
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    --l;
    pair<ll, ll> q = query(l, r);
    cout << abs(q.second - q.first) << endl;
  }
  return 0;
}
