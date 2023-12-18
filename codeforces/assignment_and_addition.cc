#include <iostream>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
struct st {
  int n;
  vector<pair<ll, ll>> seg;
  vector<bool> marked;
  st(int n) : n(n), seg(4 * n + 1, {0, 0}), marked(4 * n + 1, false) {}
  void push(ll id, ll L, ll R) {
    if (marked[id]) {
      ll M = (L + R) / 2;
      seg[2 * id + 1] = seg[2 * id + 2] = seg[id];
      seg[2 * id + 1].first = (M - L + 1) * seg[id].second;
      seg[2 * id + 2].first = (R - M) * seg[id].second;
      seg[id].second = 0;
      marked[2 * id + 1] = marked[2 * id + 2] = true;
      marked[id] = false;
    }
  }
  void update(ll l, ll r, ll v) { update(HEAD, 0, n - 1, l, r, v); }
  void update(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (l > r)
      return;
    if (L == l && r == R) {
      seg[id].first = (r - l + 1) * v;
      seg[id].second = v;
      marked[id] = true;
      return;
    }
    push(id, L, R);
    ll M = (L + R) / 2;
    update(2 * id + 1, L, M, l, min(M, r), v);
    update(2 * id + 2, M + 1, R, max(l, M + 1), r, v);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].second;
  }
  ll query(ll l, ll r) { return query(HEAD, 0, n - 1, l, r); }
  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return 0;
    if (L == l && r == R)
      return seg[id].first;
    push(id, L, R);
    ll M = (L + R) / 2;
    return query(2 * id + 1, L, M, l, min(M, r)) +
           query(2 * id + 2, M + 1, R, max(M + 1, l), r);
  }
};
int main() {
  freopen("sample", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  auto tree = st(n);
  int op, a, b;
  ll c;
  for (int i = 0; i < q; i++) {
    cin >> op >> a >> b;
    if (op == 1) {
      cin >> c;
      tree.update(a, b - 1, c);
    } else {
      cout << tree.query(a, b - 1) << endl;
    }
  }
  return 0;
}
