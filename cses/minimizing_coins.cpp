#include <set>
#include <math.h>
#include <stdio.h>

#define INF 100000000

int n, k;

std::set<long long> coins;
bool memoized[200001];
long long memo[200001];

long long min(long long a, long long b) {
  return (a > b) ? b : a;
}

long long solve(int x) {
  if (x < 0)
    return -1;
  if (x == 0)
    return 0;

  long long best = (long long)INF;
  for (long long c : coins) {
    best = min(best, solve(x-c) + 1);
  }

  return best;
}

int main() {
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; i++) {
    long long t;
    scanf("%lld", &t);
    coins.insert(t);
  }

  printf("%lld\n", solve(k));
}
