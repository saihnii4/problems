#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

long long dp[1000001];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  vector<long long> coins(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &coins[i]);
  }

  for (int i = 0; i <= x; i++) {
    dp[i] = INT_MAX;
  }

  dp[0] = 0;
  
  for (int i = 1; i <= n; i++) {
    for (int weight = 0; weight <= x; weight++) {
      if (weight - coins[i - 1] >= 0) {
        dp[weight] = min(dp[weight], dp[weight - coins[i - 1]] + 1);
      }
    }
  }

  printf("%lld\n", (dp[x] == INT_MAX ? -1 : dp[x]));
}
