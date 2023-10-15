#include <iostream>
#define MOD (int)1e9+7
using ll = long long;
using namespace std;
int n, m;
ll dp[100001][101];
int main() {
  cin >> n >> m;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (arr[0] == 0)
    for (int i = 0; i <= m; i++)
      dp[0][i] = 1;
  else
    dp[0][arr[0]] = 1;

  for (int i = 1; i < n; i++) {
    if (arr[i] == 0) {
      for (int j=1;j<=m;j++) {
        dp[i][j] = dp[i-1][j];
        if (j > 1) dp[i][j] += dp[i-1][j-1];
        if (j+1 <= m) dp[i][j] += dp[i-1][j+1];
        dp[i][j] %= MOD;
      }
    } else {
      dp[i][arr[i]] = dp[i-1][arr[i]];
      if (arr[i] > 1) dp[i][arr[i]] += dp[i-1][arr[i]-1];
      if (arr[i] + 1 <= m) dp[i][arr[i]] += dp[i-1][arr[i]+1];
      dp[i][arr[i]] %= MOD;
    }
  }
  ll total = 0;
  for (int i=1;i<=m;i++) {
    total += dp[n-1][i];
    total %= MOD;
  }
  cout << total << endl;
  return 0;
}
