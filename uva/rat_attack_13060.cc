#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define MAX ((ll)1e9)
int main() {
  /* ios_base::sync_with_stdio(false); */
  /* cin.tie(NULL); */
  /* freopen("sample", "r", stdin); */
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    vector<vector<ll>> dp(1025, vector<ll>(1025, 0));
    cin >> d;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x, y, s;
      cin >> x >> y >> s;
      for (int i = max(0, x - d); i <= min(1024, x + d); i++) {
        for (int j = max(0, y - d); j <= min(1024, y + d); j++) {
          dp[i][j] += s;
        }
      }
    }
    array<ll, 3> ans = {MAX, MAX, -MAX};
    for (int i = 0; i < 1024; i++) {
      for (int j = 0; j < 1024; j++) {
        if (dp[i][j] > ans[2]) {
          ans[0] = i;
          ans[1] = j;
          ans[2] = dp[i][j];
        }
      }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
  }
  return 0;
}
