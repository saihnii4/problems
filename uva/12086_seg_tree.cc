#include <iostream>
#include <sstream>
#include <vector>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
template <typename T> struct PURQBSegTree {
  vector<T> arr;
  vector<T> seg;
  T DEFAULT_VALUE;
  int n;

  PURQBSegTree(vector<T> nodes, T def)
      : n(nodes.size()), arr(nodes), seg(2 * nodes.size()), DEFAULT_VALUE(def) {
    build();
  }

  PURQBSegTree(int n, T filler)
      : arr(n, filler), n(n), seg(4 * n), DEFAULT_VALUE(filler) {
    build();
  }

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
    for (seg[i += n] = v; i > 1; i >>= 1) {
      seg[i >> 1] = merge(seg[i], seg[i ^ 1]);
    }
  }

  T merge(T l, T r) { return l + r; }
};
char op;
int n, a, cs = 1;
ll b;
int main() {
  for (;;) {
    cin >> n;
    vector<ll> arr(n);
    if (n == 0)
      break;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    auto tree = PURQBSegTree<ll>(arr, 0);
    if (cs > 1)
      cout << endl;
    cout << "Case " << cs << ":" << endl;
    string line;
    cin.get();
    getline(cin, line);
    for (;;) {
      stringstream ss(line);
      if (line == "END")
        break;
      ss >> op >> a >> b;
      if (op - 'M' == 0) {
        cout << tree.query(a - 1, b) << endl;
      } else {
        tree.update(a - 1, b);
      }
      getline(cin, line);
    }
    ++cs;
  }
}
