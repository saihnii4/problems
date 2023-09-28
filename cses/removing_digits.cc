#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<long long> dp(1000001, 1e9);

int main() {
  ll n;
  cin >> n;

  dp[0] = 0;

  for (int i = 0; i <= n; i++) {
    for (char c : to_string(i)) {
      dp[i] = min(dp[i], dp[i-(c-'0')]+1);
    }
  }

  cout << dp[n] << endl;
}