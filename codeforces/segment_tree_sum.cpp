#include <stdio.h>

long long arr[100000];
long long sum[400000];
int n, m;

void build(long long id, long long L, long long R) {
  if (L == R) {
    sum[id] = arr[L];
    return;
  }
  long long M = (L + R) / 2;
  build(2*id+1, L, M);
  build(2*id+2, M+1, R);
  sum[id] = sum[2*id+1] + sum[2*id+2];
}

void update(long long id, long long L, long long R, long long i, long long val) {
  if (L == R) {
    sum[id] = val;
    return;
  }
  long long M = (L + R) / 2;
  if (i <= M) update(2*id+1, L, M, i, val);
  else update(2*id+2, M + 1, R, i, val);
  sum[id] = sum[2*id+1] + sum[2*id+2];
}

long long query(long long id, long long L, long long R, long long l, long long r) {
  if (L == l && R == r) {
    return sum[id];
  }
  long long M = (L + R) / 2;
  if (r <= M) return query(2*id+1, L, M, l, r);
  else if (l >= M + 1) return query(2*id + 2, M + 1, R, l, r);
  else return query(2*id + 1, L, M, l, M) + query(2*id + 2, M + 1, R, M + 1, r);
}

int main() {
  scanf("%d %d", &n ,&m);

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  build(1, 0, n - 1);

  for (int i = 0; i < m; i++) {
    int op, el;
    long long val;
    scanf("%d %d %lld", &op, &el, &val);

    if (op == 1) update(1, 0, n - 1, el, val);
    else printf("%lld\n", query(1, 0, n - 1, el, val - 1));
  }
  
  return 0;
}
