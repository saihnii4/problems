#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
typedef ll node;
// slightly faster implementation using bitwise operations
// uses half as much memory
struct BSegTree {
  int HEAD = 0, n;
  vector<node> arr, seg;
  node DEFAULT_VALUE;
  BSegTree(int n, vector<node> nodes, node deft) : n(n), arr(nodes), seg(2 * n), DEFAULT_VALUE(deft) {
    for (int i = 0; i < n; i++) {
      seg[n + i] = arr[i];
    }
    build();
  }

  void build() {
    for (int i = n - 1; i > 0; --i) {
      seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
  }

  void update(ll i, ll v) {
    for (seg[i += n] = v; i > 1; i >>= 1)
      seg[i >> 1] = merge(seg[i], seg[i ^ 1]);
  }

  node query(ll l, ll r) {
    node ans = DEFAULT_VALUE;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) ans = merge(ans, seg[l++]);
      if (r&1) ans = merge(ans, seg[--r]);
    }
    return ans;
  }

  node merge(node l, node r) { return l + r; }
};
// barebones unoptimized segment tree
/* struct SegTree { */
/*   int HEAD = 0, n; */
/*   vector<node> arr, seg; */
/*  */
/*   SegTree(int n, vector<node> nodes) : n(n), arr(nodes), seg(4 * n + 1) { */
/*     build(this->HEAD, 0, n - 1); */
/*   } */
/*  */
/*   SegTree(int n, node val) : n(n), seg(4 * n + 1) { */
/*     for (int i = 0; i < n; i++) { */
/*       this->arr[i] = val; */
/*     } */
/*     build(this->HEAD, 0, n - 1); */
/*   } */
/*  */
/*   node merge(ll l, ll r) { */
/*     // implement */
/*     return l + r; */
/*   } */
/*  */
/*   void build(ll id, ll L, ll R) { */
/*     if (L == R) { */
/*       this->seg[id] = this->arr[L]; */
/*       return; */
/*     } */
/*     ll M = (L + R) / 2; */
/*     this->build(2 * id + 1, L, M); */
/*     this->build(2 * id + 2, M + 1, R); */
/*     this->seg[id] = merge(this->seg[2 * id + 1], this->seg[2 * id + 2]); */
/*   } */
/*  */
/*   void update(ll id, ll L, ll R, ll i, ll v) { */
/*     if (L == R) { */
/*       this->seg[id] = v; */
/*       return; */
/*     } */
/*     ll M = (L + R) / 2; */
/*     if (i <= M) */
/*       this->update(2 * id + 1, L, M, i, v); */
/*     else */
/*       this->update(2 * id + 2, M + 1, R, i, v); */
/*     seg[id] = this->merge(seg[2 * id + 1], seg[2 * id + 2]); */
/*   } */
/*  */
/*   void update(ll i, ll v) { this->update(this->HEAD, 0, this->n - 1, i, v); }
 */
/*  */
/*   node query(ll L, ll R) { */
/*     return this->query(this->HEAD, 0, this->n - 1, L, R); */
/*   } */
/*  */
/*   node query(ll id, ll L, ll R, ll l, ll r) { */
/*     if (L == l && r == R) */
/*       return this->seg[id]; */
/*     ll M = (L + R) / 2; */
/*     if (r <= M) */
/*       return this->query(2 * id + 1, L, M, l, r); */
/*     else if (l >= M + 1) */
/*       return this->query(2 * id + 2, M + 1, R, l, r); */
/*     else */
/*       return this->merge(this->query(2 * id + 1, L, M, l, M), */
/*                          this->query(2 * id + 2, M + 1, R, M + 1, r)); */
/*   } */
/* }; */
int n, q;
int main() {
  cin >> n >> q;
  vector<node> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  auto tree = BSegTree(n, arr, 0);
  for (int i = 0; i < q; i++) {
    int op, a;
    ll b;
    cin >> op >> a >> b;
    if (op == 1) {
      tree.update(a - 1, b);
    } else {
      cout << tree.query(a - 1, b) << endl;
    }
  }
}
