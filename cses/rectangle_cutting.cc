#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int x, y;
  cin >> x >> y;
  vector<vector<ll> > dp(x+1, vector<ll>(y+1, 1e9));
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      if (i == j)
        dp[i][j] = 0;
      for (int k=1;k<i;k++) {
        dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
      }
      for (int k=1;k<j;k++) {
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
      }
    }
  }
  cout << dp[x][y] << endl;
  return 0;
}
