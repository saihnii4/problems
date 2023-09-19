#include <iostream>

using namespace std;

long long arr[100000];
long long st[400000];

int n, m;

long long min(long long a, long long b) { return (a > b) ? b : a; };

void build(long long id, long long L, long long R) {
  if (L == R) {
    st[id] = arr[L];
    return;
  }

  long long M = (L + R) / 2;
  build(2*id+1, L, M);
  build(2*id+2, M+1, R);
  st[id] = min(st[2*id+1], st[2*id+2]);
}

void update(long long id, long long L, long long R, long long i, long long val) {
  if (L == R) {
    st[id] = val;
    return;
  }

  long long M = (L + R) / 2;
  if (i <= M) update(2*id+1, L, M, i, val);
  else update(2*id+2, M+1, R, i, val);
  st[id] = min(st[2*id+1], st[2*id+2]);
}

long long query(long long id, long long L, long long R, long long l, long long r) {
  if (L == l && R == r) {
    return st[id];
  }
  
  long long M = (L + R) / 2;

  if (r <= M) return query(2*id+1, L, M, l, r);
  else if (l >= M + 1) return query(2*id+2, M+1, R, l, r); // M + 1!!!
  else return min(query(2*id+1, L, M, l, M), query(2*id+2, M+1, R, M+1, r));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  build(1, 0, n - 1);

  for (int i = 0; i < m; i++) {
    int op, a;
    long long b;
    cin >> op >> a >> b;

    if (op == 1) update(1, 0, n - 1, a, b);
    else if (op == 2) cout << query(1, 0, n - 1, a, b - 1) << endl;
  }

  return 0;
}
