#include <iostream>
typedef long long ll;
using namespace std;
ll n, m, dp[100000][100], arr[100000];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  if (arr[0] == 0) {
    for (int i = 0; i < n; i++) {
      dp[0][i] = 1;
    }
  } else {
    dp[0][arr[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (arr[i] == 0) {
      for (int j = m; j < m + 4; j++) {
        for (int k = arr[i] - 1; k <= arr[i] + 1; k++) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
      }
    } else {
      for (int j = m; j < m + 4; j++) {
        for (int k  = arr[i] - 1; k <= arr[i] + 1)
      }
    }
  }
}
