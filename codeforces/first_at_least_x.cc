#include <stdio.h>
#include <utility>
#define ll long long
#define HEAD_NODE 0
 
using namespace std;
typedef pair<ll, ll> node;
ll arr[100000], b;
node seg[400000];
int n, m, op, a;
node merge(node l, node r) {
  if (l.first >= r.first)
    return l;
  return r;
}

void build(ll id, ll L, ll R) {
  if (L == R) {
    seg[id] = node(arr[L], L);
    return;
  }

  ll M = (L + R) / 2;

  build(2 * id + 1, L, M);
  build(2 * id + 2, M + 1, R);
  seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}

void update(ll id, ll L, ll R, ll i, ll v) {
  if (L == R) {
    seg[id] = node(v, i);
    return;
  }
  ll M = (L + R) / 2;
  if (i <= M)
    update(2 * id + 1, L, M, i, v);
  else
    update(2 * id + 2, M + 1, R, i, v);
  seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}

node query(ll id, ll L, ll R, ll x) {
  if (L == R)
    return (x <= seg[id].first) ? seg[id] : node(0, -1);
  ll M = (L + R) / 2;
  if (seg[2 * id + 1].first >= x)
    return query(2 * id + 1, L, M, x);
  else
    return query(2 * id + 2, M + 1, R, x);
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  build(HEAD_NODE, 0, n - 1);

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &op, &a);

    if (op == 1) {
      scanf("%lld", &b);
      update(HEAD_NODE, 0, n - 1, a, b);
    } else
      printf("%lld\n", query(HEAD_NODE, 0, n - 1, a).second);
  }

  return 0;
}
