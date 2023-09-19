#include <bits/stdc++.h>

using namespace std;

const int N = 200000;
long long sum[4 * N];
int a[N];

void build(int id, int L, int R) {
  if (L == R) {
    sum[id] = a[L];
    return;
  }
  int M = (L + R) / 2;
  build(2 * id + 1, L, M);
  build(2 * id + 2, M + 1, R);
  sum[id] = sum[2 * id + 1] + sum[2 * id + 2];
}

void update(int id, int L, int R, int i) {
  if (L == R) {
    sum[id]++;
    return;
  }
  int M = (L + R) / 2;
  if (i <= M) update(2 * id + 1, L, M, i);
  else update(2 * id + 2, M + 1, R, i);
  sum[id] = sum[2 * id + 1] + sum[2 * id + 2];
}

long long query(int id, int L, int R, int l, int r) {
  if (L == l && r == R) return sum[id];
  int M = (L + R) / 2;
  if (r <= M) return query(2 * id + 1, L, M, l, r);
  else if (M + 1 <= l) return query(2 * id + 2, M + 1, R, l, r);
  else return query(2 * id + 1, L, M, l, M) + query(2 * id + 2, M + 1, R, M + 1, R);
}

int main() {
  for (int i = 1; i < 18; i++) {
    a[i] = i;
  }

  build(1, 0, 17);

  printf("%lld", query(1, 0, 17, 3, 4));
}
