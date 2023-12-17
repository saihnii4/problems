#include <iostream>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
struct SegTree {
  int n;
  vector<ll> seg;
  vector<ll> marked;
  SegTree(int n) : n(n), seg(4 * n + 1, 0), marked(4 * n + 1, false) { return; }
  void push(ll id) {
    if (marked[id]) {
      seg[2 * id + 1] = seg[2 * id + 2] = seg[id];
      marked[2*id+1] = marked[2*id+2] = true;
      marked[id] = false;
    }
  }

  void update(ll l, ll r, ll v) { update(HEAD, 0, n - 1, l, r, v); }
  void update(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (l > r)
      return;
    if (L == l && r == R) {
      seg[id] = v;
      marked[id] = true;
      return;
    }
    push(id);
    ll M = (L + R) / 2;
    update(2 * id + 1, L, M, l, min(r, M), v);
    update(2 * id + 2, M + 1, R, max(M + 1, l), r, v);
  }

  ll query(ll i) { return query(HEAD, 0, n - 1, i); }
  ll query(ll id, ll L, ll R, ll i) {
    if (L == R) {
      return seg[id];
    }
    push(id);
    ll M = (L + R) / 2;
    if (i <= M)
      return query(2 * id + 1, L, M, i);
    else
      return query(2 * id + 2, M + 1, R, i);
  }
};
int main() {
  /* freopen("sample", "r", stdin); */
  int n, q;
  cin >> n >> q;
  auto tree = SegTree(n);
  int op, a, b;
  ll c;
  for (int i = 0; i < q; i++) {
    cin >> op >> a;
    if (op == 1) {
      cin >> b >> c;
      tree.update(a, b - 1, c);
    } else {
      cout << tree.query(a) << endl;
    }
  }
}
