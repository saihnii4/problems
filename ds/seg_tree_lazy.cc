// TODO: revisit
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
using ll = long long;
int n, q;
/* template <typename T> struct LazySegTree { */
/*   int n; */
/*   vector<T> seg, lazy; */
/*   T DEFAULT; */
/*  */
/*   void propagate(int id) { */
/*     seg[id << 1] += lazy[id]; */
/*     lazy[id << 1] += lazy[id]; */
/*     seg[id << 1 | 1] += lazy[id]; */
/*     lazy[id << 1 | 1] += lazy[id]; */
/*     lazy[id] = 0; */
/*   } */
/*  */
/*   LazySegTree(vector<T> arr, T def) */
/*       : n(arr.size()), seg(2 * arr.size(), 0), lazy(2 * arr.size(), 0), */
/*         DEFAULT(def) { */
/*     for (int i = 0; i < n; i++) { */
/*       seg[i + n] = arr[i]; */
/*     } */
/*     for (int i = n - 1; i > 0; i--) */
/*       seg[i] = seg[i << 1] + seg[i << 1 | 1]; */
/*   } */
/*  */
/*   // [l, r) */
/*   ll query(ll l, ll r) { */
/*     T cum = DEFAULT; */
/*     for (l += n, r += n; l < r; l >>= 1, r >>= 1) { */
/*       if (l & 1) cum += seg[l++]; */
/*       if (r & 1) cum += seg[--r]; */
/*     } */
/*     return cum; */
/*   } */
/*  */
/*   void update(ll id, ll L, ll R, ll l, ll r, T v) { */
/*     if (L==l&&r==R) { // covers whole interval */
/*       seg[id] += v; */
/*       lazy[id] += v; */
/*       return; */
/*     } */
/*     propagate(id); */
/*     ll M=(L+R)/2; */
/*     if (r <= M) update(id<<1, L, M, l, r, v); */
/*     else if (l >= M+1) update(id<<1|1, M+1,R,l,r,v); */
/*     else { */
/*       update(id<<1,L,M,l,M,v); */
/*       update(id<<1|1,M+1,R,M+1,r,v); */
/*     } */
/*     seg[id] = seg[id<<1] + seg[id<<1|1]; */
/*   } */
/* }; */
template <typename T> struct LazySegTree {
  int n, HEAD_NODE = 0;
  vector<T> seg, arr, lazy;
  T DEFAULT;

  LazySegTree(vector<T> arr, T def)
      : n(arr.size()), seg(4 * arr.size(), 0), arr(arr),
        lazy(4 * arr.size(), 0), DEFAULT(def) {
    build(HEAD_NODE, 0, n - 1);
  }

  void propagate(ll id) {
    if (!lazy[id])
      return;
    cout << id << ' ' << lazy[id] << endl;
    seg[2 * id + 1] += lazy[id];
    seg[2 * id + 2] += lazy[id];
    lazy[2 * id + 1] += lazy[id];
    lazy[2 * id + 2] += lazy[id];
    lazy[id] = 0;
  }

  void build(ll id, ll L, ll R) {
    if (L == R) {
      seg[id] = arr[L];
      return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
  }

  ll query(ll l, ll r) { return query(HEAD_NODE, 0, n - 1, l, r); }

  void update(ll l, ll r, T v) { update(HEAD_NODE, 0, n - 1, l, r, v); }

  ll query(ll id, ll L, ll R, ll l, ll r) {
    if (L == l && r == R)
      return seg[id];
    propagate(id);
    ll M = (L + R) / 2;
    if (r <= M)
      return query(2 * id + 1, L, M, l, r);
    else if (l >= M + 1)
      return query(2 * id + 2, M + 1, R, l, r);
    else
      return query(2 * id + 1, L, M, l, M) +
             query(2 * id + 2, M + 1, R, M + 1, r);
  }

  void update(ll id, ll L, ll R, ll l, ll r, T v) {
    if (L == l && r == R) {
      lazy[id] += v;
      seg[id] += v;
      return;
    }
    propagate(id);
    ll M = (L + R) / 2;
    if (r <= M)
      update(2 * id + 1, L, M, l, r, v);
    else if (l >= M + 1)
      update(2 * id + 2, M + 1, R, l, r, v);
    else {
      update(2 * id + 1, L, M, l, M, v);
      update(2 * id + 2, M + 1, R, M + 1, r, v);
    }
    seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
  }

  void visualize(vector<ll> v, ll id, ll L, ll R, int level) {
    cout << ((level > 0) ? string(level, '.') : "") << v[id] << endl;
    if (L==R) return;
    ll M = (L + R) / 2;
    visualize(v, 2 * id + 1, L, M, level + 1);
    visualize(v, 2 * id + 2, M + 1, R, level + 1);
  }
};
int main() {
  freopen("sample", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  auto tree = LazySegTree<ll>(arr, 0);
  tree.visualize(tree.lazy, tree.HEAD_NODE, 0, n - 1, 0);
  cout << endl;
  tree.visualize(tree.seg, tree.HEAD_NODE, 0, n - 1, 0);

  tree.update(0, 3, 1);
  cout << tree.query(0, 3) << endl;
  tree.visualize(tree.lazy, tree.HEAD_NODE, 0, n - 1, 0);
  cout << endl;
  tree.visualize(tree.seg, tree.HEAD_NODE, 0, n - 1, 0);
  /* tree.update(0, 4, 1); */
  /* cout << tree.query(0, 4) << endl; */
  /* for (int i = 0; i < q; i++) { */
  /*   int op, a, b; */
  /*   cin >> op >> a >> b; */
  /*   if (op == 1) { */
  /*  */
  /*   } else { */
  /*   } */
  /* } */
}
