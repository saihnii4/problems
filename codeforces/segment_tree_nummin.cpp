#include <stdio.h>
#include <utility>

using namespace std;

typedef pair<long long, long long> p;

int n, m;
long long arr[100000];
p st[400000];

p min(p a, p b) { return (a.first < b.first) ? a : b; };

void build(long long id, long long L, long long R) {
  if (L == R) {
    st[id] = p(arr[L], 1);
    return;
  }
  long long M = (L + R) / 2;
  build(2 * id + 1, L, M);
  build(2 * id + 2, M + 1, R);
  if (st[2*id+1].first == st[2*id+2].first)
    st[id] = p(st[2*id+1].first, st[2*id+1].second+st[2*id+2].second);
  else st[id] = min(st[2 * id + 1], st[2 * id + 2]);
}

void update(long long id, long long L, long long R, long long i,
            long long val) {
  if (L == R) {
    st[id] = p(val, 1);
    return;
  }

  long long M = (L + R) / 2;

  if (i <= M)
    update(2 * id + 1, L, M, i, val);
  else
    update(2 * id + 2, M + 1, R, i, val);
  if (st[2*id+1].first == st[2*id+2].first)
    st[id] = p(st[2*id+1].first, st[2*id+1].second+st[2*id+1].second);
  else st[id] = min(st[2 * id + 1], st[2 * id + 2]);
}

p query(long long id, long long L, long long R, long long l, long long r) {
  if (L == R)
    return st[id];
  long long M = (L + R) / 2;

  if (r <= M)
    return query(2 * id + 1, L, M, l, r);
  else if (l >= M + 1)
    return query(2 * id + 2, M + 1, R, l, r);
  else
    return min(query(2 * id + 1, L, M, l, M),
               query(2 * id + 2, M + 1, R, M + 1, r));
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  build(0, 0, n - 1);

  for (int i = 0; i < m; i++) {
    int op, a;
    long long b;
    scanf("%d %d %lld", &op, &a, &b);
    if (op == 1)
      update(0, 0, n - 1, a, b);
    else {
      p result = query(0, 0, n - 1, a, b - 1);
      printf("%lld %lld\n", result.first, result.second);
    }
  }
}
