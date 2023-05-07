#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>
 
std::vector<long long> a;
std::set< long long, std::greater<long long> > b;
 
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
    b.insert(a[i]);
    return a[i];
  }
 
  long long value = max(a[i], a[i] + traverse(i + 1, n), 0);
  b.insert(value);
  return value;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    long long n;
    std::cin >> n;

    long long count = 0;

    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        if (t) ++count;
        a.push_back(t ? (-1) : (1));
    }

    traverse(0, n);

    printf("%lld\n", count + (*b.begin()));
}
