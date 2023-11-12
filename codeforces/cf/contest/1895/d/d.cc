#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
ll arr[200000], dp[200000];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    dp[i] = dp[i - 1] ^ arr[i - 1];
  }
  ll max_el = *max_element(dp, dp+n);
  while (max_el >= n) {
    ll correction = max_el ^ (n - 1);
    for (int i = 0; i < n; i++) {
      dp[i] ^= correction;
    }
    max_el = *max_element(dp, dp+n);
  }
  for (int i=0;i<n;i++) {
    cout << dp[i] << ' ';
  }
  cout << endl;
}
