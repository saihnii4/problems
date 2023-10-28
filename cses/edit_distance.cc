#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long; 
string a,b;
int main() {
  cin >> a;
  cin >> b;
  vector<vector<int>> dp(5001, vector<int>(5001, 1e9));
  dp[0][0] = 0;
  for (int i=0;i<=a.size();i++) {
    for (int j=0;j<=b.size();j++) {
      if (i != 0) {
        dp[i][j] = min(dp[i][j], 1+dp[i-1][j]);
      }
      if (j != 0) {
        dp[i][j] = min(dp[i][j], 1+dp[i][j-1]);
      }
      if (i != 0 && j != 0) {
        dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1] != b[j-1]));
      }
    }
  }
  cout << dp[a.size()][b.size()] << endl;
  return 0;
}
