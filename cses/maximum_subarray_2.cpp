#include <stdio.h>
#include <limits.h>
#include <set>

using namespace std;

long long n, a, b, max_sum = LLONG_MIN;
multiset<long long> c;

int main() {
  scanf("%lld %lld %lld", &n, &a, &b);
  long long parr[n+1];
  parr[0] = 0;

  for (int i = 0; i < n; i++) {
    scanf("%lld", &parr[i+1]);
    parr[i+1] = parr[i] + parr[i+1];
  }

  for (int i = a; i <= n; i++) {
    if (i > b) {
      c.erase(c.find(parr[i - b - 1]));
    }

    c.insert(parr[i - a]);
    long long sum = parr[i] - *c.begin();
    if (sum > max_sum) max_sum = sum;
  }

  printf("%lld\n", max_sum);
}
