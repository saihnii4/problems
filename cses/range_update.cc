#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
typedef ll node;
int n, q;

struct BSegTree {
  int HEAD = 0, n;
  vector<node> arr, seg;
  node DEFAULT_VALUE;

  BSegTree(int n, vector<node> nodes, node deft)
      : n(n), arr(nodes), seg(2 * n), DEFAULT_VALUE(deft) {
    for (int i = 0; i < n; i++) {
      seg[n + i] = arr[i];
    }
    build();
  }
  BSegTree(int n, node filler) : n(n), seg(2 * n), DEFAULT_VALUE(filler) {
    for (int i = 0; i <= 2 * n; i++) {
      seg[i] = 0;
    }
    build();
  }

  void build() {
    for (int i = n - 1; i > 0; --i) {
      seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
  }

  void update(ll i, ll v) {
    for (seg[i += n] += v; i > 1; i >>= 1)
      seg[i >> 1] = merge(seg[i], seg[i ^ 1]);
  }

  node query(ll l, ll r) {
    node ans = DEFAULT_VALUE;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        ans = merge(ans, seg[l++]);
      if (r & 1)
        ans = merge(ans, seg[--r]);
    }
    return ans;
  }

  node merge(node l, node r) { return l + r; }
};

// scrapped
/* template <typename T, typename... Args, typename TCtx> */
/* inline void _unit_test(TCtx ctx, function<T(Args...)> impl, T expected, Args... args) { */
/*   static_assert(ctx->*impl(args...) == expected); */
/* } */

int main() {
  cin >> n >> q;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  auto tree = BSegTree(n + 1, 0);
  auto test_tree = BSegTree(4, 1);
  /* _unit_test(test_tree, &BSegTree::query, 2, 0, 2); */
  for (int i = 0; i < q; i++) {
    int op, a, b;
    ll k;
    cin >> op >> a;
    if (op == 1) {
      cin >> b >> k;
      tree.update(a - 1, k);
      tree.update(b, -k);
    } else {
      cout << arr[a - 1] + tree.query(0, a) << endl;
    }
  }
}
