#include <set>
#include <stdio.h>
#include <tuple>
#include <utility>

using namespace std;

typedef tuple<long long, pair<int, int> > el;
int n;
long long k, mx = -1;
set<el> s;

bool check(int a, int b, int c, int d) {
  return a != b && a != c && a != d && b != c && b != d && c != d;
}

int main() {
  scanf("%d %lld", &n, &k);
  long long arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    if (arr[i] > mx) mx = arr[i];
  }

  if (mx * 4 < k) {
      printf("IMPOSSIBLE\n");
      return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      if (i != j) {
        if (arr[i] + arr[j] > k)
          continue;
        s.insert(el(arr[i] + arr[j], pair<int, int>(i, j)));
      }
  }

  for (el e : s) {
    for (el j : s)
      if (e != j && check(get<1>(e).first, get<1>(e).second, get<1>(j).first,
                          get<1>(j).second)) {
        if (get<0>(e) + get<0>(j) == k) {
          printf("%d %d %d %d\n", get<1>(e).first + 1, get<1>(e).second + 1,
                 get<1>(j).first + 1, get<1>(j).second + 1);
          return 0;
        }
      }
  }

  printf("IMPOSSIBLE\n");
  return 0;
}
