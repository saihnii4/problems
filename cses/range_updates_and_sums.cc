#include <iostream>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
vec<ll> arr;
struct st {
  int n;
  vec<pair<ll, pair<ll, ll>>> seg;
  st() : n(arr.size()), seg(4 * n + 1, {0, {0, 0}}) { build(HEAD, 0, n - 1); }
  void build(ll id, ll L, ll R) {
    if (L == R) {
      seg[id] = {arr[L], {0, 0}};
      return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  void apply(ll id, ll sz, pair<ll, ll> op) {
    if (op.second) {
      seg[id].first = sz * op.second;
      seg[id].second.first = 0;
      seg[id].second.second = op.second;
    }
    if (op.first) {
      seg[id].first += sz * op.first;
      seg[id].second.first += op.first;
    }
  }
  void push(ll id, ll L, ll R) {
    ll M = (L + R) / 2;
    apply(2 * id + 1, M - L + 1, seg[id].second);
    apply(2 * id + 2, R - M, seg[id].second);
    seg[id].second = {0, 0};
  }
  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return 0;
    if (L == l && r == R)
      return seg[id].first;
    push(id, L, R);
    ll M = (L + R) / 2;
    return query(2 * id + 1, L, M, l, min(M, r)) +
           query(2 * id + 2, M + 1, R, max(l, M + 1), r);
  }
  ll query(ll l, ll r) { return query(HEAD, 0, n - 1, l, r); }
  void increment(ll id, ll L, ll R, ll l, ll r, ll x) {
    if (l > r)
      return;
    if (L == l && r == R) {
      seg[id].first += x * (R - L + 1);
      seg[id].second.first += x;
      return;
    }
    push(id, L, R);
    ll M = (L + R) / 2;
    increment(2 * id + 1, L, M, l, min(M, r), x);
    increment(2 * id + 2, M + 1, R, max(l, M + 1), r, x);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  void increment(ll l, ll r, ll x) { increment(HEAD, 0, n - 1, l, r, x); }
  void assign(ll id, ll L, ll R, ll l, ll r, ll x) {
    if (l > r)
      return;
    if (L == l && r == R) {
      seg[id].first = x * (R - L + 1);
      seg[id].second.second = x;
      seg[id].second.first = 0;
      return;
    }
    push(id, L, R);
    ll M = (L + R) / 2;
    assign(2 * id + 1, L, M, l, min(M, r), x);
    assign(2 * id + 2, M + 1, R, max(l, M + 1), r, x);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  void assign(ll l, ll r, ll x) { assign(HEAD, 0, n - 1, l, r, x); }
};
int main() {
  /* freopen("sample", "r", stdin); */
  int n, q;
  cin >> n >> q;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  auto tree = st();
  int op, a, b;
  ll x;
  for (int i = 0; i < q; i++) {
    cin >> op >> a >> b;
    switch (op) {
    case 1:
      cin >> x;
      tree.increment(a - 1, b - 1, x);
      break;
    case 2:
      cin >> x;
      tree.assign(a - 1, b - 1, x);
      break;
    case 3:
      cout << tree.query(a - 1, b - 1) << endl;
      break;
    }
  }
}
