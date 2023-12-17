#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n, d;
int main() {
  freopen("sample", "r", stdin);
  cin >> n >> d;
  vector<vector<ll>> dp((1 << n), vector<ll>(d, 0));
  vector<vector<ll>> prices(n, vector<ll>(d, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      cin >> prices[i][j];
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    dp[1 << i][0] = prices[i][0];
  }
  for (int i = 0; i < d; i++) {
    for (int j = 1; j < (1 << n); j++) {
      dp[j][i] = dp[j][i - 1];
      for (int k = 0; k < n; k++) {
        if (j & (1 << k)) {
          dp[j][i] = min(dp[j][i], dp[j ^ (1 << k)][i - 1] + prices[k][i]);
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][d - 1] << endl;
  return 0;
}
