#include <stdio.h>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef pair<long long, long long> pairwise;

vector<long long> a;
multiset<pairwise> b;

long long x, y;

long long max(long long a, long long b, long long c) {
  long long t = a;
  if (b > t)
    t = b;
  if (c > t)
    t = c;
  return t;
}

long long traverse(long long i, long long n, long long len) {
  if (i == 0 && a[i] < 0)
    return traverse(1, n, 1);
  if (i == n) {
    b.insert(pairwise(len, a[i]));
    return a[i];
  }

  long long value = max(a[i], a[i] + traverse(i + 1, n, len + 1), 0);
  b.insert(pairwise(len, value));
  return value;
}

int main() {
  long long n, m;
  bool d = true;
  scanf("%lld %lld %lld", &n, &x, &y);

  for (long long i = 0; i < n; i++) {
    long long l;
    scanf("%lld", &l);

    if (l > 0) d = false;

    if (i == 0 || l > m)
      m = l;

    a.push_back(l);
  }

  traverse(0, n, 1);
  long long max = get<1>(*b.begin());

  auto lbound = b.lower_bound(pairwise(x, 0));
  auto ubound = b.upper_bound(pairwise(y, 0));

  for (auto it = lbound; it != ubound; it++) {
    long long val = get<1>(*it);
    if (val > max)
      max = val;
  }

  if (d)
    printf("%lld\n", m);
  else
    printf("%lld\n", max);

  return 0;
}
