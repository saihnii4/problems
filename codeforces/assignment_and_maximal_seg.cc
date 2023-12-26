#include <iostream>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;
int n, m;
ll min(ll a, ll b) { return (a > b) ? (b) : (a); }
ll max(ll a, ll b) { return (a > b) ? (a) : (b); }
ll max(ll a, ll b, ll c) {
  ll d = (a > b) ? a : b;
  ll e = (c > d) ? c : d;
  return (d > e) ? d : e;
}
struct node {
  ll pref;
  ll suf;
  ll sum;
  ll sol;
};
struct st {
  int n;
  vector<pair<node, ll>> seg;
  vector<bool> marked;
  st(int n)
      : n(n), seg(4 * n + 1, {{0, 0, 0, 0}, 0}), marked(4 * n + 1, false) {
    return;
  }
  void push(ll id, ll L, ll R) {
    if (marked[id]) {
      ll M = (L + R) / 2;
      seg[2 * id + 1].second = seg[2 * id + 2].second = seg[id].second;
      ll leftsum = (M - L + 1) * seg[id].second;
      seg[2 * id + 1].first = {max(0, leftsum), max(0, leftsum), leftsum,
                               max(0, leftsum)};
      ll rightsum = (R - M) * seg[id].second;
      seg[2 * id + 2].first = {max(0, rightsum), max(0, rightsum), rightsum,
                               max(0, rightsum)};
      marked[2 * id + 1] = marked[2 * id + 2] = true;
      marked[id] = false;
    }
  }
  node merge(node l, node r) {
    ll sum = l.sum + r.sum;
    ll pref = max(l.pref, l.sum + r.pref);
    ll suf = max(r.suf, r.sum + l.suf);
    ll sol = max((ll)0, max(l.sol, r.sol, l.suf + r.pref));
    return {pref, suf, sum, sol};
  }
  void update(ll l, ll r, ll v) { update(HEAD, 0, n - 1, l, r, v); }
  void update(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (l > r)
      return;
    if (L == l && r == R) {
      ll sum = (R - L + 1) * v;
      seg[id].first = {max(0, sum), max(0, sum), sum, max(0, sum)};
      seg[id].second = v;
      marked[id] = true;
      return;
    }
    /* cout << L << ' ' << R << endl; */
    push(id, L, R);
    ll M = (L + R) / 2;
    update(2 * id + 1, L, M, l, min(M, r), v);
    update(2 * id + 2, M + 1, R, max(l, M + 1), r, v);
    seg[id].first = merge(seg[2 * id + 1].first, seg[2 * id + 2].first);
  }
};
int main() {
  /* freopen("sample", "r", stdin); */
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  auto tree = st(n);
  int a, b;
  ll c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    tree.update(a, b - 1, c);
    cout << tree.seg[HEAD].first.sol << endl;
  }
  return 0;
}
