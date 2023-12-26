#include <iostream>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
vector<ll> arr;
struct st {
  int n;
  vector<pair<ll, pair<ll, ll>>> seg;
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
  void push(ll id, ll L, ll R, ll orl, ll orr) {
    seg[2 * id + 1].second.second += seg[id].second.second;
    seg[2 * id + 2].second.second += seg[id].second.second;
    ll M = (L + R) / 2;
    seg[2 * id + 1].second.first =
        seg[id].second.first; // left node has same offset
    seg[2 * id + 2].second.first = M - orl;
    seg[2*id+1].first = seg[2*id+1].second.first*(M-L+1) + (seg[2*id+1].second.second*(M-L+1)*(M-L+2) >> 1);
    seg[2*i+2].first = seg[2*id+2].second.first*(R-M)
    seg[id].second.second = 0;
  }
  void update(ll id, ll L, ll R, ll l, ll r, ll orl, ll orr) {
    if (l > r)
      return;
    if (L == l && r == R) {
      seg[id].second.first += l - orl;
      seg[id].second.second++;
      seg[id].first = seg[id].second.first * (R - L + 1) +
                      (seg[id].second.second * (R - L + 1) * (R - L + 2) >> 1);
      return;
    }
    push(id, L, R, orl, orr);
    ll M = (L + R) / 2;
    update(2 * id + 1, L, M, l, min(M, r), orl, orr);
    update(2 * id + 2, M + 1, R, max(l, M + 1), r, orl, orr);
    seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
  }
  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return 0;
    if (L == l && r == R)
      return seg[id];
  }
};
int main() {
  int n;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  auto tree = st();
  int op, a, b;
  for (int i = 0; i < q; i++) {
    cin >> op >> a >> b;
    if (op == 1) {
      tree.update(a - 1, b - 1);
    } else {
      cout << tree.query(a - 1, b - 1) << endl;
    }
  }
  return 0;
}
