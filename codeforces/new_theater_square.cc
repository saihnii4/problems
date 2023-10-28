// TODO: i'm dum

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int t;
ll dp[1001][1001];
int main() {
  cin >> t;
  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
      string str;
      cin >> str;
      for (int j = 1; j <= m; j++) {
        if (str.c_str()[j] == '*') {
          dp[i][j] = -1;
        } else {
          dp[i][j] = 0;
        }
      }
    }
    dp[0][0]=x;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
        if (dp[i][j] == -1) {
          dp[i][j] = min(dp[i][j-1], dp[i][j-2]);
          continue;
        }
        dp[i][j] = x;
        if (j >= 1) {
          dp[i][j] = min(dp[i][j], dp[i][j-1] + x);
          dp[i][j] = min(dp[i][j], dp[i][j-2] + y);
        }
      }
    }
    cout << dp[n][m] << endl;
  }
  return 0;
}
