#include <stdio.h>
#include <vector>

std::vector<long long> a;
std::vector<long long> b;

long long max(long long a, long long b, long long c) {
  long long t = a;
  if (b > t)
    t = b;
  if (c > t)
    t = c;
  return t;
}

long long traverse(long long i, long long n) {
  if (i == 0 && a[i] < 0)
    return traverse(1, n);
  if (i == n) {
    b.push_back(a[i]);
    return a[i];
  }

  long long value = max(a[i], a[i] + traverse(i + 1, n), 0);
  b.push_back(value);
  return value;
}

int main() {
  long long n, m;
  bool d = true;
  scanf("%lld", &n);

  for (long long i = 0; i < n; i++) {
    long long l;
    scanf("%lld", &l);

    if (l > 0) d = false;

    if (i == 0 || l > m)
      m = l;

    a.push_back(l);
  }

  traverse(0, n);
  long long max = b[0];

  for (long long i = 0; i < b.size(); i++)
    if (b[i] > max)
      max = b[i];

  if (d)
    printf("%lld\n", m);
  else
    printf("%lld\n", max);
}
