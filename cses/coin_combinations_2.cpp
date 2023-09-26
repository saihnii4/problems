#include <stdio.h>

using namespace std;

int n;
long long x, dp[10000001], MOD = (int)1e9 + 7;

int main() {
  dp[0] = 1;
  scanf("%d %lld", &n, &x);
  long long coins[n];

  for (int i = 0; i < n; i++) {
    scanf("%lld", &coins[i]);
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i <= x; i++) {
      if (i - coins[j] >= 0) {
        dp[i] += dp[i - coins[j]];
        dp[i] %= MOD;
      }
    }
  }

  printf("%lld\n", dp[x]);

  return 0;
}
