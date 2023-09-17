#include <stdio.h>

int n;
long long dp[1000001];

long long MOD = 1e9 + 7;

int main() {
  scanf("%d", &n);

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 8;
  dp[5] = 16;
  dp[6] = 32;

  if (n > 5)
    for (int i = 6; i <= n; i++) 
      dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % MOD;

  printf("%lld\n", dp[n]);
  
  return 0;
}
