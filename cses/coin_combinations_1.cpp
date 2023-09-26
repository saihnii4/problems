#include <stdio.h>
#include <set>

using namespace std;

multiset<long long> coins;

long long n, x, dp[100000001];
long long MOD = (int)1e9 + 7;

int main() {
  dp[0] = 1;

  scanf("%lld %lld", &n, &x);
  long long coins[n];

  for (int i = 0; i < n; i++) {
    scanf("%lld", &coins[i]);
  }

  for (long long i = 0; i <= x; i++) {
    for (long long j = 0; j < n; j++) {
      if (i - coins[j] >= 0) {
        dp[i] += dp[i - coins[j]];
        dp[i] %= MOD;
      }
    }
  }

  printf("%lld\n", dp[x]);

  return 0;
}
