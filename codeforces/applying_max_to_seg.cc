#include <algorithm>
#include <iostream>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
struct SegTree {
  int n;
  vector<ll> seg;
  vector<ll> arr;
  SegTree(vector<ll> arr) : n(arr.size()), seg(4 * n + 1), arr(arr) {}

  void update(ll l, ll r, ll v) { update(HEAD, 0, n - 1, l, r, v); }

  ll query(ll i) { return query(HEAD, 0, n - 1, i); }

  void update(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (l > r) return;
    if (L == l && r == R) {
      seg[id] = max(seg[id], v);
      return;
    }
    ll M = (L + R) / 2;
    update(2 * id + 1, L, M, l, min(r, M), v);
    update(2 * id + 2, M + 1, R, max(M + 1, l), r, v);
  }

  ll query(ll id, ll L, ll R, ll i) {
    if (L == R)
      return seg[id];
    ll M = (L + R) / 2;
    ll tmp = -1e9;
    if (i <= M)
      tmp = max(tmp, query(2 * id + 1, L, M, i));
    else
      tmp = max(tmp, query(2 * id + 2, M + 1, R, i));
    return max(tmp, seg[id]);
  }
};
int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> arr(n, 0);
  auto tree = SegTree(arr);
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
