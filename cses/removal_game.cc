#include <iostream>
using namespace std;
using ll = long long;
ll dp[5000][5000];
ll x[5000];
ll tot;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    tot += x[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      dp[i][j] = -1e9 - 1;
      if (i == j)
        dp[i][j] = x[i];
      else
        dp[i][j] = max(x[i]-dp[i+1][j], x[j]-dp[i][j-1]);
    }
  }
  cout << (tot+dp[0][n-1])/2 << endl;
}
