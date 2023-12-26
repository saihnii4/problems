// TODO: fix

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
using node = pair<pair<ll, ll>, bool>;
struct st {
  int n;
  vector<node> seg;
  st(int n) : n(n), seg(4 * n + 1, {{0, 0}, 0}) { build(HEAD, 0, n - 1); }
  node merge(node l, node r) {
    return {{l.first.first + r.first.first, r.first.second},
            l.second || r.second};
  }
  void build(ll id, ll L, ll R) {
    if (L == R) {
      seg[id] = {{0, L}, 0};
      return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
  }
  void apply(ll id, ll sz) { seg[id].first = {sz - seg[id].first.first, true}; }
  void push(ll id, ll L, ll R) {
    if (seg[id].second) {
      ll M = (L + R) / 2;
      apply(2 * id + 1, M - L + 1);
      apply(2 * id + 2, R - M);
      seg[id].second = false;
    }
  }
  void update(ll l, ll r) { update(HEAD, 0, n - 1, l, r); }
  void update(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return;
    if (L == l && r == R) {
      seg[id].first.first = (R - L + 1) - seg[id].first.first;
      seg[id].second = true;
      return;
    }
    push(id, L, R);
    ll M = (L + R) / 2;
    update(2 * id + 1, L, M, l, min(M, r));
    update(2 * id + 2, M + 1, R, max(l, M + 1), r);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
  }
  ll query(ll i) { return query(HEAD, 0, n - 1, i); }
  ll query(ll id, ll L, ll R, ll i) {
    if (L == R)
      return seg[id].first.second;
    push(id, L, R);
    ll M = (L + R) / 2;
    if (seg[2 * id + 1].first.first <= i)
      return query(2 * id + 2, M + 1, R, i - seg[2 * id + 1].first.first);
    else
      return query(2 * id + 1, L, M, i);
  }
};
int main() {
  freopen("sample", "r", stdin);
  int n, q;
  cin >> n >> q;
  auto tree = st(n);
  int op, a, b;
  for (int i = 0; i < q; i++) {
    cin >> op >> a;
    if (op == 1) {
      cin >> b;
      tree.update(a, b - 1);
    } else {
      cout << tree.query(i) << endl;
    }
  }
  return 0;
}
