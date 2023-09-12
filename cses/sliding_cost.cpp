#include <set>
#include <stdio.h>

using namespace std;

long long _a;
long long _b;

multiset<long long> a;
multiset<long long> b;

int n, k;

void ins(long long val) {
  long long c = *a.rbegin();

  if (val > c) {
    b.insert(val);
    _b += val;
    if (b.size() > k / 2) {
      a.insert(*b.begin());
      _b -= *b.begin();
      _a += *b.begin();
      b.erase(b.find(*b.begin()));
    }
  } else {
    a.insert(val);
    _a += val;
    if (a.size() > (k + 1) / 2) {
      b.insert(*a.rbegin());
      _a -= *a.rbegin();
      _b += *a.rbegin();
      a.erase(a.find(*a.rbegin()));
    }
  }
}

void er(long long val) {
  if (a.find(val) != a.end()) {
    _a -= val;
    a.erase(a.find(val));
  } else {
    b.erase(b.find(val));
    _b -= val;
  }

  if (a.empty()) {
    a.insert(*b.begin());
    _a += *b.begin();
    _b -= *b.begin();
    b.erase(b.find(*b.begin()));
  }
}

int main() {
  scanf("%d %d", &n, &k);

  long long arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  a.insert(arr[0]);

  _a += arr[0];

  for (int i = 1; i < k; i++) {
    ins(arr[i]);
  }

  printf("%lld ", (k > 2) ? *a.rbegin() - _a + _b : _b - _a);

  for (int i = k; i < n; i++) {
    if (k == 1) {
      ins(arr[i]);
      er(arr[i - k]);
    } else {
      er(arr[i - k]);
      ins(arr[i]);
    }

    printf("%lld ", (k > 2) ? *a.rbegin() - _a + _b : _b - _a);
  }

  printf("\n");

  return 0;
}
