#include <utility>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> book;
book b[1001];
int dp[1001][100001],n,x;
ll MOD=(int)1e9+7;
int main() {
  cin>>n>>x;
  for (int i=0;i<n;i++){
    cin>>b[i].first;
  }
  for (int i=0;i<n;i++) {
    cin>>b[i].second;
  }
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= x; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      dp[i][j] = dp[i-1][j];
      if (j >= b[i-1].first)
        dp[i][j] = max(dp[i][j], dp[i-1][j-b[i-1].first]+b[i-1].second);
      dp[i][j] %= MOD;
    }
  }
  cout << dp[n][x] << endl;
  return 0;
}
