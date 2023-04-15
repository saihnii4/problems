#include <set>
#include <algorithm>
#include <stdio.h>
#include <tuple>

using namespace std;

typedef tuple<int, long long> e;
int n;
set<e> s = {};

bool cmp(e x, e y) {
    return get<1>(x) < get<1>(y);
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    long long t;
    scanf("%lld", &t);
    s.insert(e(i + 1, t));
  }

  for (e el : s) {
    auto iter = make_reverse_iterator(--(lower_bound(s.begin(), s.find(el), el, cmp)));

    if (iter.base() == s.begin()) continue;

    while (iter.base() != s.begin()) {
        printf("%d %lld\n", get<0>(*iter), get<1>(*iter));
        ++iter;
    }

    printf("\n");
  }
}
