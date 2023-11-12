#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

template <typename T> struct PURQSegTree {
  static const int HEAD_NODE = 0;
  int n;
  vector<T> arr;
  vector<T> seg;
  PURQSegTree(vector<T> nodes)
      : arr(nodes), seg(4 * nodes.size()), n(nodes.size()) {
    build(HEAD_NODE, 0, n - 1);
  }

  PURQSegTree(int n, T filler) : arr(n, filler), n(n), seg(4 * n) {
    build(HEAD_NODE, 0, n - 1);
  }

  void build(ll id, ll L, ll R) {
    if (L == R) {
      seg[id] = arr[L];
      return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
  }

  T query(ll L, ll R) { return query(HEAD_NODE, 0, n - 1, L, R); }

  T query(ll id, ll L, ll R, ll l, ll r) {
    if (L == l && r == R)
      return seg[id];
    ll M = (L + R) / 2;
    if (r <= M)
      return query(2 * id + 1, L, M, l, r);
    else if (l >= M + 1)
      return query(2 * id + 2, M + 1, R, l, r);
    else
      return merge(query(2 * id + 1, L, M, l, M),
                   query(2 * id + 2, M + 1, R, M + 1, r));
  }

  void update(ll i, ll v) { update(HEAD_NODE, 0, n - 1, i, v); }

  void update(ll id, ll L, ll R, ll i, T v) {
    if (L == R) {
      op(id, v);
      return;
    }
    ll M = (L + R) / 2;
    if (i <= M)
      update(2 * id + 1, L, M, i, v);
    else
      update(2 * id + 2, M + 1, R, i, v);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
  }

  // DO implement the following functions

  // fuck it, inline that shit :p
  void op(ll id, T val) { seg[id] = val; }

  // implement merge (this only works when T supports the (+) operator)
  T merge(T l, T r) { return l + r; }
};

// Iterative, bitwise implementation
// memory efficient too
// inspired by the codeforces blog of a similar name i think
template <typename T> struct PURQBSegTree {
  vector<T> arr;
  vector<T> seg;
  T DEFAULT_VALUE;
  int n;

  PURQBSegTree(vector<T> nodes, T def)
      : n(nodes.size()), arr(nodes), seg(2 * nodes.size()), DEFAULT_VALUE(def) {
    build();
  }

  PURQBSegTree(int n, T filler) : arr(n, filler), n(n), seg(4 * n), DEFAULT_VALUE(filler) { build(); }

  void build() {
    for (int i = 0; i < n; i++)
      seg[n + i] = arr[i];
    for (int i = n - 1; i > 0; i--)
      seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
  }

  T query(ll l, ll r) {
    T ans = DEFAULT_VALUE;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        ans = merge(ans, seg[l++]);
      if (r & 1)
        ans = merge(ans, seg[--r]);
    }
    return ans;
  }

  void update(ll i, T v) {
    for (seg[i += n] += v; i > 1; i >>= 1) {
      seg[i >> 1] = merge(seg[i], seg[i ^ 1]);
    }
  }

  T merge(T l, T r) { return l + r; }
};

// AC for cses dynamic range sum queries
/* int main() { */
/*   int n, q; */
/*   cin >> n >> q; */
/*   vector<ll> arr(n); */
/*   for (int i = 0; i < n; i++) { */
/*     cin >> arr[i]; */
/*   } */
/*   // C++ 11 requires template arguments !! */
/*   auto tree = PURQBSegTree<ll>(arr, 0); */
/*   for (int i = 0; i < q; i++) { */
/*     int op, a; */
/*     ll b; */
/*     cin >> op >> a >> b; */
/*     if (op == 1) { */
/*       tree.update(a - 1, b); */
/*     } else { */
/*       cout << tree.query(a - 1, b) << endl; */
/*     } */
/*   } */
/*   return 0; */
/* } */

// AC on Range Update Queries CSES
/* int main() { */
/*   int n, q; */
/*   cin >> n >> q; */
/*   vector<ll> arr(n); */
/*   for (int i = 0; i < n; i++) { */
/*     cin >> arr[i]; */
/*   } */
/*   auto tree = PURQBSegTree<ll>(n + 1, 0); */
/*   for (int i = 0; i < q; i++) { */
/*     int op, a, b; */
/*     ll u; */
/*     cin >> op >> a; */
/*     if (op == 1) { */
/*       cin >> b >> u; */
/*       tree.update(a-1, u); */
/*       tree.update(b, -u); */
/*     } else { */
/*       cout << arr[a-1] + tree.query(0, a) << endl; */
/*     } */
/*   } */
/*   return 0; */
/* } */
seg
