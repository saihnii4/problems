#include <set>
#include <stdio.h>

using namespace std;

int n, k;

multiset<long long> a;
multiset<long long> b;

void ins(long long val) {
  long long c = *a.rbegin();

  if (val > c) {
    b.insert(val);
    if (b.size() > k / 2) {
      a.insert(*b.begin());
      b.erase(b.find(*b.begin()));
    }
  } else {
    a.insert(val);
    if (a.size() > (k + 1) / 2) {
      b.insert(*a.rbegin());
      a.erase(a.find(*a.rbegin()));
    }
  }
}

void er(long long val) {
  if (a.find(val) != a.end()) a.erase(a.find(val));
  else b.erase(b.find(val));

  if (a.empty()) {
    a.insert(*b.begin());
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

  for (int i = 1; i < k; i++)
    ins(arr[i]);

  printf("%lld ", *a.rbegin());

  for (int i = k; i < n; i++) {
    if (k == 1) {
      ins(arr[i]);
      er(arr[i - k]);
    } else {
      er(arr[i - k]);
      ins(arr[i]);
    }

    printf("%lld ", *a.rbegin());
  }

  printf("\n");

  return 0;
}
