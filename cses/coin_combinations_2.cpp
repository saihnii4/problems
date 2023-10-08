#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int x, dp[1000001], MOD = (int)1e9 + 7;

int main() {
  dp[0] = 1;
  scanf("%d %d", &n, &x);
  int coins[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &coins[i]);
  }

  sort(coins, coins + n);

  for (int j = 0; j < n; j++) {
    for (int i = 0; i <= x; i++) {
      if (i - coins[j] >= 0) {
        dp[i] += dp[i - coins[j]];
        dp[i] %= MOD;
      }
    }
  }

  printf("%d\n", dp[x]);

  return 0;
}
