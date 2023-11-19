#include <iostream>
using namespace std;
using ll = long long;
#define MOD (ll)(1e9 + 7)
int n;
ll dp[500][500*(501)>>1];
int main() {
  cin >> n;
  if (n*(n+1) & 2) {
    cout << 0 << endl;
    return 0;
  }

  dp[0][0] = 1;
  for (int i=1;i<n;i++) {
    for (int j=0;j<=(n*(n+1)>>2);j++) {
      dp[i][j] = dp[i-1][j] + (j - i >= 0 ? dp[i-1][j-i] : 0);
      dp[i][j] %= MOD;
    }
  }

  cout << dp[n-1][(n*(n+1)>>2)] << endl;
  return 0;
}
