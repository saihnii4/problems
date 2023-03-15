#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

long long count(long long n) {
  long long a = 1, c = 0;
  while (a <= n) {
    a *= 2;
    ++c;
  }
  return c;
}

int main() {
  long long n;
  scanf("%lld", &n);
  long long i = count(n);

  vector<long long> a;

  if ((n & 1) == 0)
    printf("Impossible\n");
  else {
    long long k = (long long)pow(2, i - 1) + (n >> 1);
    for (long long j = 0; j < i; j++) {
      if ((k & (1 << j)) == 0)
        a.push_back(-(1 << j));
      else
        a.push_back(1 << j);
    }

    printf("%d\n", a.size());

    for (long long i = 0; i < a.size(); i++) {
      if (a[i] > 0)
        printf("+%lld", a[i]);
      else
        printf("%lld", a[i]);
    }
    printf("\n");
  }

  return 0;
}
