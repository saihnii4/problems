#include <iostream>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
vector<ll> arr;
int n, m;
struct st {
  int n;
  vector<pair<ll, ll>> seg;
  st(int n) : n(n), seg(4 * n + 1, {0, 0}) { build(HEAD, 0, n - 1); }
  void build(ll id, ll L, ll R) {
    if (L == R) {
      seg[id].first = arr[L];
      return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  void push(ll id) {
    seg[2 * id + 1].first ^= seg[id].second;
    seg[2 * id + 1].second ^= seg[id].second;
    seg[2 * id + 2].first ^= seg[id].second;
    seg[2 * id + 2].second ^= seg[id].second;
    seg[id].second = 0;
  }
  void update(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (l > r)
      return;
    if (L == l && r == R) {
      seg[id].first ^= v;
      seg[id].second ^= v;
      return;
    }
    ll M = (L + R) / 2;
    push(id);
    update(2 * id + 1, L, M, l, min(M, r), v);
    update(2 * id + 2, M + 1, R, max(l, M + 1), r, v);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return 0;
    if (L == l && r == R)
      return seg[id].first;
    push(id);
    ll M = (L + R) / 2;
    return query(2 * id + 1, L, M, l, min(M, r)) +
           query(2 * id + 2, M + 1, R, max(l, M + 1), r);
  }
};
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  auto tree = st(n);
  cin >> m;
  int op, a, b;
  ll c;
  for (int i = 0; i < m; i++) {
    cin >> op >> a >> b;
    if (op == 1) {
      cout << tree.query(a, b) << endl;
    } else {
      tree.update(a, b - 1, c);
    }
  }
}
