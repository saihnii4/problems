#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
using ll = long long;
struct SegTree {
  int n;
  vector<ll> seg;

  SegTree(vector<ll> arr) : n(arr.size()), seg(2 * arr.size(), 0) {
    for (int i = 0; i < n; i++)
      seg[n + i] = arr[i];
    for (int i = n - 1; i > 0; i--)
      seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
  }

  SegTree(int n, ll filler) : n(n), seg(2 * n, 0) {
    for (int i = 0; i < n; i++)
      seg[n + i] = filler;
    for (int i = n - 1; i > 0; i--)
      seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
  }

  void update(ll i, ll v) {
    for (seg[i += n] = v; i > 1; i >>= 1) {
      seg[i >> 1] = min(seg[i], seg[i ^ 1]);
    }
  }

  ll query(ll l, ll r) {
    ll ans = 1e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        ans = min(ans, seg[l++]);
      if (r & 1)
        ans = min(ans, seg[--r]);
    }
    return ans;
  }
};
int n, q;
int main() {
  cin >> n >> q;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  SegTree down(n+1, 0), up(n+1, 0);
  for (int i = 1; i <= n; i++) {
    down.update(i, arr[i-1] - i);
    up.update(i, arr[i-1] + i + 1);
  }
  for (int i = 0; i < q; i++) {
    int op, a;
    ll b;
    cin >> op >> a;
    if (op == 1) {
      cin >> b;
      arr[a - 1] = b;
      down.update(a, arr[a - 1] - a);
      up.update(a, arr[a - 1] + a);
    } else {
      cout << min(down.query(0, a) + a, up.query(a, n - 1) - a) << endl;
    }
  }
  return 0;
}
