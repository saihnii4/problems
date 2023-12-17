#include <iostream>
#include <math.h>
using namespace std;
using ll = long long;
ll dp[200001][100];
int n, q;
void build() {
  int k = floor(log2(n));
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
    }
  }
}
ll query(ll l, ll r) {
  ll ans = 1e9;
  while (l < r) {
    int k = floor(log2(r - l + 1));
    ans = min(ans, dp[l][k - 1]);
    l += (1 << (k - 1));
  }
  return ans;
}
int main() {
  /* freopen("sample", "r", stdin); */
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> dp[i][0];
  }
  build();
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << query(a-1, b) << endl;
  }
  return 0;
}
