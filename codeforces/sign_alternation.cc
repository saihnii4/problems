#include <iostream>
#define HEAD_NODE 0
#include <utility>
using namespace std;
using ll = long long;
typedef pair<ll, int> node;
node seg[400000];
ll arr[100000];
node merge(node l, node r) {
  return {l.first * l.second + r.first * r.second, 1};
}
void build(ll id, ll L, ll R) {
  if (L == R) {
    seg[id] = {arr[L], (L & 1) ? -1 : 1};
    return;
  }
  ll M = (L + R) / 2;
  build(2 * id + 1, L, M);
  build(2 * id + 2, M + 1, R);
  seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}
node query(ll id, ll L, ll R, ll l, ll r) {
  if (L == l && r == R)
    return seg[id];
  ll M = (L + R) / 2;
  if (r <= M)
    return query(2 * id + 1, L, M, l, r);
  else if (l >= M + 1)
    return query(2 * id + 2, M + 1, R, l, r);
  else
    return merge(query(2 * id + 1, L, M, l, M),
                 query(2 * id + 2, M + 1, R, M + 1, r));
}
void update(ll id, ll L, ll R, ll i, ll v) {
  if (L == R) {
    seg[id] = { v, seg[id].second };
    return;
  }
  ll M=(L+R)/2;
  if (i <= M) update(2*id+1,L,M,i,v);
  else update(2*id+2,M+1,R,i,v);
  seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}
int main() {
  /* freopen("sample","r",stdin); */
  int n, q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(HEAD_NODE, 0, n - 1);
  cin >> q;
  for (int i = 0; i < q; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 0) {
      update(HEAD_NODE, 0, n - 1, a - 1, b);
    } else {
      node q = query(HEAD_NODE, 0, n - 1, a - 1, b - 1);
      cout << (((a-1) & 1) ? -1 : 1) * q.first << endl;
    }
  }
}
