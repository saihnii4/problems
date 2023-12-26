#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
int n, q;
vector<ll> arr;
struct st {
  int n;
  vector<pair<ll, pair<ll, ll>>> seg;
  vector<bool> marked;
  st() : n(arr.size()), seg(4 * n + 1, {0, {0, 0}}), marked(4 * n + 1, false) {
    build(HEAD, 0, n - 1);
  }
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
    switch (op.first) {
    case 1:
      seg[id].first += sz * op.second;
      break;
    case 2:
      seg[id].first = sz * op.second;
      break;
    }
  }
  // caller decides whether to nullify lazy value
  void push(ll id, ll L, ll R) {
    // no operation on node
    if (seg[id].second.first == 0)
      return;
    ll M = (L + R) / 2;
    apply(2 * id + 1, M - L + 1, seg[id].second);
    seg[2 * id + 1].second = seg[id].second;
    apply(2 * id + 2, R - M, seg[id].second);
    seg[2 * id + 2].second = seg[id].second;
    seg[id].second = {0, 0};
  }
  void increment(ll l, ll r, ll v) { increment(HEAD, 0, n - 1, l, r, v); }
  void increment(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (l > r)
      return;
    if (L == l && r == R) {
      if (seg[id].second.first > 0) {
        apply(id, R - L + 1, seg[id].second);
        if (R - L > 1)
          push(id, L, R);
        seg[id].second = {1, v};
      }
      return;
    }
    push(id, L, R);
    ll M = (L + R) / 2;
    increment(2 * id + 1, L, M, l, min(M, r), v);
    increment(2 * id + 2, M + 1, R, max(l, M + 1), r, v);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  void assign(ll l, ll r, ll v) { assign(HEAD, 0, n - 1, l, r, v); }
  void assign(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (l > r)
      return;
    if (L == l && r == R) {
      if (seg[id].second.first > 0) {
        apply(id, R - L + 1, seg[id].second);
        if (R - L > 1)
          push(id, L, R);
        seg[id].second = {2, v};
      }
      return;
    }
    push(id, L, R);
    ll M = (L + R) / 2;
    assign(2 * id + 1, L, M, l, min(M, r), v);
    assign(2 * id + 2, M + 1, R, max(l, M + 1), r, v);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  ll query(ll l, ll r) { return query(HEAD, 0, n - 1, l, r); }
  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return 0;
    ll M = (L + R) / 2;
    if (L == l && r == R)
      return seg[id].first;
    push(id, L, R);
    return query(2 * id + 1, L, M, l, min(M, r)) +
           query(2 * id + 2, M + 1, R, max(l, M + 1), r);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("sample", "r", stdin);
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
  return 0;
}
