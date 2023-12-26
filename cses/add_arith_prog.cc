#include <iostream>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
using node = pair<ll, pair<ll, ll>>;
struct st {
  int n;
  vector<ll> arr;
  vector<pair<ll, pair<ll, ll>>> seg;
  st(vector<ll> arr) : n(arr.size()), seg(4 * n + 1, {0, 0}), arr(arr) {
    build(HEAD, 0, n - 1);
  }
  void apply(ll id, ll sz, ll in) {
    seg[id].first += ((sz) * (sz + 1) >> 1) - ((in) * (in + 1) >> 1);
    seg[id].second = {};
  }
  void push(ll id, ll l, ll r) {
    if (seg[id].second > make_pair((ll)0, (ll)0)) {
      ll m = (l + r) / 2;
      apply(2 * id + 1, m - l + 1, 0);
      apply(2 * id + 2, r - m, m - 1);
      seg[id].second = {-1, -1};
    }
  }
  void build(ll id, ll l, ll r) {
    if (l == r) {
      seg[id] = {arr[l], {0, 0}};
      return;
    }
    ll m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m + 1, r);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  void update(ll id, ll L, ll R, ll l, ll r) {
    if (l > r) return;
    if (L == l && r == R) {

    }
  }
  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return 0;
    if (L == l && r == R)
      return seg[id].first;
    ll M = (L + R) / 2;
    push(id, L, R);
    return query(2 * id + 1, L, M, l, min(M, r)) +
           query(2 * id + 2, M + 1, R, max(l, M + 1), r);
  }
};
int main() {
  freopen("sample", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int op, a, b;
  for (int i = 0; i < q; i++) {
    cin >> op >> a >> b;
    if (op == 1) {

    } else {
    }
  }
}
