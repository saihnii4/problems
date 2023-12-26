#include <array>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#define HEAD 0
using namespace std;
using ll = long long;

using opstack = stack<ll>;
using operation = array<ll, 4>;

vector<ll> arr;
vector<bool> vis;
vector<vector<int>> adj;
vector<vector<operation>> ops;
struct st {
  int n;
  vector<opstack> seg;
  vector<operation> ops;
  vector<bool> marked;
  st() : n(arr.size()), seg(4 * n + 1, opstack()), marked(4*n+1, false) { build(HEAD, 0, n - 1); }
  void push(ll id, ll L, ll R) {

  }
  void build(ll id, ll L, ll R) {
    if (L == R) {
      seg[id].push(arr[L]);
      return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id].top() = seg[2 * id + 1].top() + seg[2 * id + 2].top();
  }
  ll query(ll l, ll r) { return query(HEAD, 0, n-1, l, r); }
  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (l > r)
      return 0;
    if (L == l && r == R)
      return seg[id].top();
    ll M = (L + R) / 2;
    return query(2 * id + 1, L, M, l, min(r, M)) +
           query(2 * id + 2, M + 1, R, max(M + 1, l), r);
  }
  void update(ll i, ll v) { update(HEAD, 0, n-1, i, v); }
  void update(ll id, ll L, ll R, ll i, ll v) {
    if (i < L || i > R) return;
    if (L == R) {
      seg[id].top() = v;
      return;
    }
    ll M = (L + R) / 2;
    update(2 * i + 1, L, M, i, v);
    update(2 * id + 2, M + 1, R, i, v);
    seg[id].top() = seg[2 * id + 1].top() + seg[2 * id + 2].top();
  }
  void rollback() {
    for (operation o : ops) {

    }
  }
  void rollback(ll id, ll L, ll R, ll i) {

  }
};
st seg;
void traverse(int i) {
  if (adj[i].size() != 0) {
    for (ll copy : adj[i]) {
      traverse(copy);
    }
  }
  vector<operation> operations = ops[i];
  seg.ops = operations;
  for (operation op : operations) {
    if (op[0] == 1) {
      seg.update(op[2] - 1, op[3]);
    } else {
      // TODO: store query and pop out later
      seg.query(op[2] - 1, op[3]);
    }
  }
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  st();
  ops.resize(q, {});
  int op, a, j = 1, k, b, z = 1;
  for (int i = 0; i < q; i++) {
    cin >> op >> k;
    if (op == 1 || op == 2) {
      cin >> a >> b;
      ops[k].push_back({op, k, a, b});
    } else {
      ++j;
      adj[k].push_back(j);
    }
  }
  // there's no chance of a disconnected node
  traverse(1);
  return 0;
}
