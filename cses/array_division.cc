// bniary search

#include <stdio.h>

long long n, k;
long long highest_possible, divisions;

bool valid(long long x, long long arr[]) {
  long long groups = 0;
  long long sum = 0;
  for (long long i = 0; i < n; i++){
    if (arr[i] > x) return false;
    
    if (sum + arr[i] > x) {
      ++groups;
      sum = 0;
    }

    sum += arr[i];
  }

  if (sum > 0) ++groups;

  return groups <= k;
}

int main() {
  scanf("%lld %lld", &n, &k);

  long long arr[n];

  for (long long i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    highest_possible += arr[i];
  }

  long long lb = 0, ub = highest_possible;

  while (lb <= ub) {
    long long mid = (lb + ub) / 2;

    if (valid(mid, arr)) {
      ub = mid - 1;
      divisions = mid;
    } else {
      lb = mid + 1;
    }
  }

  printf("%lld\n", divisions);

  return 0;
}
