#include <iostream>
#include <utility>
#define HEAD_NODE 0
using namespace std;
typedef long long ll;
typedef pair<ll, ll> node;
ll n, m, arr[100000], op, a, b;
node seg[400000];
node merge(node a, node b) {
  if (a.first >= b.first)
    return a;
  return b;
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
    seg[id] = node(v, L);
    return;
  }
  ll M = (L + R) / 2;
  if (i <= M)
    update(2 * id + 1, L, M, i, v);
  else
    update(2 * id + 2, M + 1, R, i, v);
  seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}
node query(ll id, ll L, ll R, ll x, ll i) {
  if (L == R)
    return (x <= seg[id].first || i <= seg[id].second) ? seg[id] : node(0, -1);
  ll M = (L + R) / 2;
  if (seg[2 * id + 1].first >= x && seg[2*id+1].second >= i)
    return query(2 * id + 1, L, M, x, i);
  else
    return query(2 * id + 2, M + 1, R, x, i);
}
int main() {
  cin >> n >> m;
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (ll i = 0; i < m; i++) {
    cin >> op >> a >> b;
    if (op == 1)
      update(HEAD_NODE, 0, n - 1, a, b);
    else
      printf("%lld\n", query(HEAD_NODE, 0, n - 1, a, b).second);
  }
}
