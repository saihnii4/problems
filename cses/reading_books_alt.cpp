// still O(n) but less convoluted

#include <algorithm>
#include <stdio.h>

using namespace std;

long long m = 0, s;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    m = max(m, x);
    s += x;
  }
  printf("%lld\n", m > (s - m) ? 2 * m : s);
  return 0;
}
