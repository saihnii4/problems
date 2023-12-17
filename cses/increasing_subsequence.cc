#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#define MAX (ll)1e9
using namespace std;
using ll = long long;
ll ans;
int main() {
  int n;
  cin >> n;
  vector<ll> arr(n, 0);
  vector<ll> dp(n+1, MAX);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  dp[0] = -MAX;
  for (int i = 0; i < n; i++) {
    int l = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); // find first number with LIS ending in a number greater than arr[i]
    if (dp[l-1] < arr[i] && arr[i] < dp[l]) {
      dp[l] = arr[i];
    }
  }

  for (int i=0;i<=n;i++) {
    if (dp[i] < MAX) ans = i;
  }

  cout << ans << endl;
}
