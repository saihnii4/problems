// index compression smh
#include <iostream>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
int n, q;
int seg[4000000004];
void update(ll id, ll L, ll R, ll i, ll v) {
  if (L == R) {
    seg[id] += v;
    return;
  }

  ll M = (L + R) / 2;
  if (i <= M)
    update(2 * id + 1, L, M, i, v);
  else
    update(2 * id + 2, M + 1, R, i, v);
  seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}
ll query(ll id, ll L, ll R, ll l, ll r) {
  if (L==l&&r==R) return seg[id];
  ll M=(L+R)/2;
  if (r <= M) return query(2*id+1,L,M,l,r);
  else if (l >= M+1) return query(2*id+2,M+1,R,l,r);
  else return query(2*id+1,L,M,l,M)+query(2*id+2,M+1,R,M+1,r);
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int l, r;
    ll v;
    cin >> l >> r >> v;
    update(HEAD_NODE, 0, n, l - 1, v);
    update(HEAD_NODE, 0, n, r, -v);
  }
  for (int i = 0; i < q; i++) {
    ll l, r;
    cout << query(HEAD_NODE, 0, n, l, r) << endl;
  }
  return 0;
}
