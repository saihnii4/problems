#include <iostream>
#include <vector>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
struct st {
  int n;
  vector<ll> arr;
  vector<ll> seg;
  st(vector<ll> arr) : n(arr.size()), arr(arr), seg(4*n+4, 0) { build(HEAD_NODE, 0, n); }
  void build(ll id, ll L, ll R) {
    if (L == R) {
      seg[id] = arr[L];
      return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
  }
  void update(ll l, ll r, ll v) {
    update(HEAD_NODE, 0, n, l, v);
    update(HEAD_NODE, 0, n, r, -v);
  }
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
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
  }
  ll query(ll l, ll r) { return query(HEAD_NODE, 0, n, l, r); }
  ll query(ll id, ll L, ll R, ll l, ll r) {
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
  ll merge(ll l, ll r) { return l + r; }
};
int n, m;
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  vector<ll> arr(n+1, 0);
  auto tree = st(arr);
  for (int i = 0; i < m; i++) {
    int op, a, b;
    ll v;
    cin >> op >> a;
    if (op == 1) {
      cin >> b >> v;
      tree.update(a, b, v);
    } else {
      cout << tree.query(0, a) << endl;
    }
  }
  return 0;
}
