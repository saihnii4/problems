#include <stdio.h>
#include <vector>

std::vector<int> a;
std::vector<int> b;

int max(int a, int b, int c) {
  int t = a;
  if (b > t)
    t = b;
  if (c > t)
    t = c;
  return t;
}

int traverse(int i, int n) {
  if (i == 0 && a[i] < 0)
    return traverse(1, n);
  if (i == n) {
    b.push_back(a[i]);
    return a[i];
  }

  int value = max(a[i], a[i] + traverse(i + 1, n), 0);
  b.push_back(value);
  return value;
}

int main() {
  int n, m;
  bool d = true;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int l;
    scanf("%d", &l);

    if (l > 0) d = false;

    if (i == 0 || l > m)
      m = l;

    a.push_back(l);
  }

  traverse(0, n);
  int max = b[0];

  for (int i = 0; i < b.size(); i++)
    if (b[i] > max)
      max = b[i];

  if (d)
    printf("%d\n", m);
  else
    printf("%d\n", max);
}
