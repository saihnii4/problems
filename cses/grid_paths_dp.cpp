#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int n;
ll dp[1000][1000],MOD=(int)1e9+7;
int main() {
  cin >> n;
  for (ll i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < n; j++) {
      if (line.c_str()[j] - '*' == 0) {
        dp[i][j] = -1;
      }
    }
  }
  if (dp[0][0] == -1){
    cout <<"0\n";
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) if ((i||j) && (dp[i][j]>=0)) {
      dp[i][j] = ((j > 0 && dp[i][j-1]>=0) ? dp[i][j - 1] : 0) + ((i > 0 && dp[i-1][j]>=0) ? dp[i - 1][j] : 0);
      dp[i][j] %= MOD;
    }
  }
  cout << max(dp[n - 1][n - 1],(ll)0) << endl;
  return 0;
}
