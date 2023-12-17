#include <iostream>
#include <limits.h>
#include <utility>
#include <vector>
#define MOD (ll)(1e9 + 7)
#define HEAD 0
using namespace std;
using ll = long long;
struct st {
  int n;
  vector<pair<ll, ll>> seg;
  st(int n) : n(n), seg(4 * n + 1, {0, 1}) { build(HEAD, 0, n - 1); }
  void build(ll id, ll L, ll R) {
    if (L == R) {
      seg[id].first = 1;
      return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  void push(ll id) {
    seg[2 * id + 1].first *= seg[id].second;
    seg[2 * id + 1].first %= MOD;
    seg[2 * id + 1].second *= seg[id].second;
    seg[2 * id + 1].second %= MOD;
    seg[2 * id + 2].first *= seg[id].second;
    seg[2 * id + 2].first %= MOD;
    seg[2 * id + 2].second *= seg[id].second;
    seg[2 * id + 2].second %= MOD;
    seg[id].second = 1;
  }
  void update(ll l, ll r, ll v) { update(HEAD, 0, n - 1, l, r, v); }
  void update(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (l > r)
      return;
    if (L == l && r == R) {
      seg[id].second *= v;
      seg[id].first *= v;
      seg[id].second %= MOD;
      seg[id].first %= MOD;
      return;
    }
    push(id);
    ll M = (L + R) / 2;
    update(2 * id + 1, L, M, l, min(M, r), v);
    update(2 * id + 2, M + 1, R, max(M + 1, l), r, v);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
    seg[id].first %= MOD;
  }
  ll query(ll l, ll r) { return query(HEAD, 0, n - 1, l, r); }
  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return 0;
    if (L == l && r == R) {
      return seg[id].first;
    }
    ll M = (L + R) / 2;
    push(id);
    return ((query(2 * id + 1, L, M, l, min(M, r)) % MOD) +
           query(2 * id + 2, M + 1, R, max(M + 1, l), r) % MOD) % MOD;
  }
};
int main() {
  /* freopen("sample", "r", stdin); */
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  auto tree = st(n);
  int op, a, b;
  ll c;
  for (int i = 0; i < m; i++) {
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
