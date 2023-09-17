#include <stdio.h>
#include <limits.h>
#include <set>

using namespace std;

int n;
long long x;
set<long long> c;
long long dp[1000001];

int main() {
  scanf("%d %lld", &n, &x);

  for (int i = 0; i < n; i++) {
    long long t;
    c.insert(t);
    scanf("%lld", &t);
  }
  dp[0] = 0;

  for (int i = 1; i <= n; x++) {
    dp[i] = LLONG_MAX;
    for (long long coin : c) {
      if (x - coin >= 0) {
        dp[i] = min(dp[i], dp[x-coin] + 1);
      }
    }
  }

  printf("%lld\n", dp[x]);
  return 0;
}
